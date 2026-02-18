/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 *
 * Copyright (C) 2026, <GROUP NUMBER>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4


// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
int tokenize(char *input, char **tokens, int i)
{

    // Returns first token
    char* token = strtok(input, " ");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL && i < 3) {
        token[strcspn(token, "\r\n")] = '\0';
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    return i;
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players)
{
    // simple bubble sort by score (descending)
    for (int i = 0; i < num_players - 1; i++)
    {
        for (int j = 0; j < num_players - i - 1; j++)
        {
            if (players[j].score < players[j + 1].score)
            {
                player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    printf("\n=== FINAL RESULTS ===\n");
    for (int i = 0; i < num_players; i++)
    {
        printf("%d. %s - %d points\n",
            i + 1,
            players[i].name,
            players[i].score);
    }
}


int main()
{
    player players[NUM_PLAYERS];
    char buffer[BUFFER_LEN] = {0};
    char *tokens[3];

    initialize_game();

    printf("=== JEOPARDY ===\n");

    // Get player names
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        printf("Enter name for player %d: ", i + 1);
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // remove newline
        initialize_player(players, buffer, i);
    }

    int questions_remaining = NUM_QUESTIONS;

    while (questions_remaining > 0)
    {
        display_categories();

        char category[BUFFER_LEN];
        char name[BUFFER_LEN];
        int value;

        printf("Who will answer?: ");
        fgets(name, BUFFER_LEN, stdin);
        name[strcspn(name, "\n")] = '\0';

        if (!player_exists(players, NUM_PLAYERS, name)) {
            printf("%s is not a player\n", name);
            continue;
        }

        printf("Enter category: ");
        fgets(category, BUFFER_LEN, stdin);
        category[strcspn(category, "\n")] = '\0';

        if (!valid_category(category))
        {
            printf("Idk what that is.\n");
            continue;
        }

        printf("Enter value: ");
        scanf("%d", &value);
        getchar();

        if (!valid_value(value))
        {
            printf("Wrong option\n");
            continue;
        }

        if (already_answered(category, value))
        {
            printf("That question was already answered.\n");
            continue;
        }

        display_question(category, value);

        printf("Your answer: ");
        fgets(buffer, BUFFER_LEN, stdin);

        int i = 0;
        i = tokenize(buffer, tokens, i);

        if (tokens[2] != NULL && i == 3) {
            char *final_answer = tokens[2];

            if (valid_answer(category, value, final_answer))
            {
                printf("Correct!\n");
                update_score(players, NUM_PLAYERS, name, value);
                questions_remaining--;
            }
            else
            {
                printf("Incorrect!\n");
            }
        }
        else {
            printf("Incorrect!\n");
        }

    }

    show_results(players, NUM_PLAYERS);
    getchar();
    return EXIT_SUCCESS;
}
