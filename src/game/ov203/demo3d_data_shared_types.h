#ifndef DEMO3D_DATA_SHARED_TYPES_H
#define DEMO3D_DATA_SHARED_TYPES_H

struct Tcbl;

struct GfFont;

/*
 * Command-system context of the demo3d demo (0x30 bytes; DEMO3D_CMDSYS_Create
 * allocates it with func_02030734(heap, 0x30, 1, ...)).  The demo3d command
 * handlers receive it as their first argument.
 */
typedef struct Demo3dCmdContext {
    unsigned short heap, alternate;   /* 0x00 */
    int config;                       /* 0x04 */
    int ended;                        /* 0x08 */
    int done;                         /* 0x0C */
    int previous;                     /* 0x10 */
    int index;                        /* 0x14 */
    unsigned char flags[4];           /* 0x18 */
    char *owner;                      /* 0x1C */
    struct Tcbl *task;                /* 0x20 */
    struct GfFont *text;              /* 0x24 */
    void *assets;                     /* 0x28 */
    int extra;                        /* 0x2C */
} Demo3dCmdContext;

typedef char Demo3dCmdContext_SizeCheck[(sizeof(Demo3dCmdContext) == 0x30) ? 1 : -1];

#endif
