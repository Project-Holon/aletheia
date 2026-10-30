#ifndef UNION_COMM_COMMAND_SHARED_TYPES_H
#define UNION_COMM_COMMAND_SHARED_TYPES_H

/* Payload of the union app commands 0x1411 and 0x1413 (0x28 bytes). */
typedef struct UnionAppData {
    int value[8];
} UnionAppData;

#endif
