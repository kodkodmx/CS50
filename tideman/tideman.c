#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote

/*Complete the vote function.
The function takes arguments rank, name, and ranks. If name is a match for the name of a valid candidate,
then you should update the ranks array to indicate that the voter has the candidate as their rank preference
(where 0 is the first preference, 1 is the second preference, etc.)

Recall that ranks[i] here represents the user’s ith preference.

The function should return true if the rank was successfully recorded,
and false otherwise (if, for instance, name is not the name of one of the candidates).

You may assume that no two candidates will have the same name.*/

bool vote(int rank, string name, int ranks[])
{
   for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            ranks[rank] = [i];
            return true
        }
      }
    return false;
}

// Update preferences given one voter's ranks
/*Complete the record_preferences function.
The function is called once for each voter, and takes as argument the ranks array,
(recall that ranks[i] is the voter’s ith preference, where ranks[0] is the first preference).

The function should update the global preferences array to add the current voter’s preferences.
Recall that preferences[i][j] should represent the number of voters who prefer candidate i over candidate j.

You may assume that every voter will rank each of the candidates.*/

void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 1 + i; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] ++;
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
/*Complete the add_pairs function.
The function should add all pairs of candidates where one candidate is preferred to the pairs array.
A pair of candidates who are tied (one is not preferred over the other) should not be added to the array.

The function should update the global variable pair_count to be the number of pairs of candidates.
(The pairs should thus all be stored between pairs[0] and pairs[pair_count - 1], inclusive).*/

void add_pairs(void)
{
    // TODO
    return;
}

// Sort pairs in decreasing order by strength of victory
/*Complete the sort_pairs function.
The function should sort the pairs array in decreasing order of strength of victory,
where strength of victory is defined to be the number of voters who prefer the preferred candidate.
If multiple pairs have the same strength of victory, you may assume that the order does not matter.*/

void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
/*Complete the lock_pairs function.
The function should create the locked graph,
adding all edges in decreasing order of victory strength so long as the edge would not create a cycle.*/

void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election

/*Complete the print_winner function.
The function should print out the name of the candidate who is the source of the graph.
You may assume there will not be more than one source.*/

void print_winner(void)
{
    // TODO
    return;
}