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
#include "questions.h"

question questions[NUM_QUESTIONS];
// Initializes the array of questions for the game
void initialize_game(void)
{

    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "What keyword is used to define a function in C?");
    strcpy(questions[0].answer, "void");
    questions[0].value = 100;
    questions[0].answered = false;

    strcpy(questions[1].category, "programming");
    strcpy(questions[1].question, "What symbol is used to access a pointer's value?");
    strcpy(questions[1].answer, "*");
    questions[1].value = 200;
    questions[1].answered = false;

    strcpy(questions[2].category, "programming");
    strcpy(questions[2].question, "Which function compares two strings in C?");
    strcpy(questions[2].answer, "strcmp");
    questions[2].value = 300;
    questions[2].answered = false;

    strcpy(questions[3].category, "programming");
    strcpy(questions[3].question, "What library contains printf?");
    strcpy(questions[3].answer, "stdio.h");
    questions[3].value = 400;
    questions[3].answered = false;


    strcpy(questions[4].category, "algorithms");
    strcpy(questions[4].question, "Q1?");
    strcpy(questions[4].answer, "A1");
    questions[4].value = 100;
    questions[4].answered = false;

    strcpy(questions[5].category, "algorithms");
    strcpy(questions[5].question, "Q2?");
    strcpy(questions[5].answer, "A2");
    questions[5].value = 200;
    questions[5].answered = false;

    strcpy(questions[6].category, "algorithms");
    strcpy(questions[6].question, "Q3?");
    strcpy(questions[6].answer, "A3");
    questions[6].value = 300;
    questions[6].answered = false;

    strcpy(questions[7].category, "algorithms");
    strcpy(questions[7].question, "Q4?");
    strcpy(questions[7].answer, "A4");
    questions[7].value = 400;
    questions[7].answered = false;


    strcpy(questions[8].category, "databases");
    strcpy(questions[8].question, "Q1?");
    strcpy(questions[8].answer, "A1");
    questions[8].value = 100;
    questions[8].answered = false;

    strcpy(questions[9].category, "databases");
    strcpy(questions[9].question, "Q2?");
    strcpy(questions[9].answer, "A2");
    questions[9].value = 200;
    questions[9].answered = false;

    strcpy(questions[10].category, "databases");
    strcpy(questions[10].question, "Q3?");
    strcpy(questions[10].answer, "A3");
    questions[10].value = 300;
    questions[10].answered = false;

    strcpy(questions[11].category, "databases");
    strcpy(questions[11].question, "Q4?");
    strcpy(questions[11].answer, "A4");
    questions[11].value = 400;
    questions[11].answered = false;

}

// Displays each of the remaining categories and question dollar values that have not been answered
// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    printf("\nAvailable Questions:\n");

    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (!questions[i].answered)
        {
            printf("Category: %s | Value: %d\n",
                questions[i].category,
                questions[i].value);
        }
    }
    printf("\n");
}


// Displays the question for the category and dollar value

void display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (strcmp(questions[i].category, category) == 0 &&
            questions[i].value == value)
        {
            printf("For %d points:\n%s\n", value, questions[i].question);
            return;
        }
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (strcmp(questions[i].category, category) == 0 &&
            questions[i].value == value)
        {
            if (strcmp(questions[i].answer, answer) == 0)
            {
                questions[i].answered = true;
                return true;
            }
            return false;
        }
    }
    return false;
}

bool valid_category(char *category) {
    for (int i = 0; i < NUM_CATEGORIES; i++)
    {
        if (strcmp(category, categories[i]) == 0) {
            return true;
        } 
    }
    return false;
}

bool valid_value(int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (value == questions[i].value) {
            return true;
        } 
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (strcmp(questions[i].category, category) == 0 &&
            questions[i].value == value && !questions[i].answered)
        {
            return questions[i].answered;
        }
    }
    return false;
}


