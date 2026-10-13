#ifndef BTLV_MCSS_SHARED_TYPES_H
#define BTLV_MCSS_SHARED_TYPES_H

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int lo : 9;    /* 0x4c */
    unsigned int f9 : 1;
    unsigned int hi : 22;
    char pad50[0x0c];
} Entry_022005C4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_022005C4 e[14];            /* 0x008 */
} Work_022005C4;

#endif
