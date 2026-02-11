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
#define STR_LEN 256
// Initializes the array of questions for the game

void initialize_game(void)
{
    // Programming (4)
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

}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
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



// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (strcmp(questions[i].category, category) == 0 &&
            questions[i].value == value)
        {
            return questions[i].answered;
        }
    }
    return false;
}


