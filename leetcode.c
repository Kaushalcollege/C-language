#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int index;
} HashEntry;

typedef struct {
    HashEntry *entries;
    int size;
} HashMap;

int hash(int key, int size) {
    return abs(key) % size;
}

HashMap* createHashMap(int size) {
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->entries = (HashEntry *)calloc(size, sizeof(HashEntry));
    map->size = size;
    return map;
}

void addToHashMap(HashMap *map, int key, int index) {
    int hashedKey = hash(key, map->size);
    while (map->entries[hashedKey].key != 0) {
        hashedKey = (hashedKey + 1) % map->size;
    }
    map->entries[hashedKey].key = key;
    map->entries[hashedKey].index = index;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    returnSize = (int *)malloc(2 * sizeof(int));
    HashMap *map = createHashMap(numsSize);
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIndex = hash(complement, map->size);
        while (map->entries[complementIndex].key != complement && map->entries[complementIndex].key != 0) {
            complementIndex = (complementIndex + 1) % map->size;
        }
        if (map->entries[complementIndex].key == complement) {
            returnSize[0] = map->entries[complementIndex].index;
            returnSize[1] = i;
            break;
        }
        addToHashMap(map, nums[i], i);
    }
    free(map->entries);
    free(map);
    return returnSize;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize; // corrected initialization
    int *indices = twoSum(nums, 4, target, &returnSize);
    printf("[%d, %d]\n", indices[0], indices[1]);
    free(indices);
    return 0;
}
