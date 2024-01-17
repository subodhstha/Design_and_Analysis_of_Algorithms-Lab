#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHARS 256

struct Node 
{
    int freq;
    char data;
    struct Node* left, *right;
};

struct MinHeap 
{
    int size;
    int capacity;
    struct Node** array;
};

// Function to create a MinHeap
struct MinHeap* createMinHeap(int capacity) 
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return minHeap;
}

// Function to swap two MinHeap nodes
void swapMinHeapNode(struct Node** a, struct Node** b) 
{
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify a subtree rooted with node idx
void minHeapify(struct MinHeap* minHeap, int idx) 
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) 
    {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if the MinHeap size is one
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Function to extract the minimum node from the MinHeap
struct Node* extractMin(struct MinHeap* minHeap) {
    if (isSizeOne(minHeap)) {
        return minHeap->array[0];
    }

    struct Node* root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Function to insert a new node into the MinHeap
void insertMinHeap(struct MinHeap* minHeap, struct Node* node) 
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) 
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = node;
}

// Function to create a Huffman tree
struct Node* createHuffmanTree(char data[], int freq[], int size) 
{
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i) 
    {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->left = node->right = NULL;
        node->data = data[i];
        node->freq = freq[i];
        insertMinHeap(minHeap, node);
    }

    // Build the Huffman tree
    struct Node *left, *right, *top;
    for (int i = 0; i < size - 1; ++i) 
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = (struct Node*)malloc(sizeof(struct Node));
        top->freq = left->freq + right->freq;
        top->data = '\0'; // Internal node doesn't hold a character
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap); // Root of the Huffman tree
}

// Function to generate Huffman codes
void generateCodes(struct Node* root, char arr[], int top) 
{
    if (root->left) 
    {
        arr[top] = '0';
        generateCodes(root->left, arr, top + 1);
    }

    if (root->right) 
    {
        arr[top] = '1';
        generateCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) 
    {
        printf("%c: %s\n", root->data, arr);
    }
}

// Function to free the memory used by the Huffman tree
void freeTree(struct Node* root) 
{
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() 
{
    char data[MAX_CHARS]; // Input data
    int freq[MAX_CHARS] = { 0 };
    int size;

    printf("Enter a string: ");
    fgets(data, MAX_CHARS, stdin); // Get input from the user
    size = strlen(data) - 1;

    if (size <= 0) {
        printf("Error: Empty input string.\n");
        return 1; // Exit with an error code
    }

    for (int i = 0; i < size; ++i) 
    {
        if (data[i] != '\n') 
        {
            ++freq[data[i]];
        }
    }

    clock_t start = clock();
    struct Node* root = createHuffmanTree(data, freq, size);
    char arr[MAX_CHARS];
    generateCodes(root, arr, 0);
    clock_t end = clock();

    double runtime = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Runtime: %f Miliseconds\n", runtime);

    // Free the memory used by the Huffman tree
    freeTree(root);

    return 0;
}
