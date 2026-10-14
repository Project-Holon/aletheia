/*
 * function: BTLV_INPUT_DeleteTask
 * address:  0x0220687C
 * packet:   pkt_ov094_0220687C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_GetTaskUserData  0x02030EE8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   BTLV_INPUT_FindTask  0x02206864  thumb  ov094
 */

typedef unsigned int   u32;
struct S02030EE8;
extern int BTLV_INPUT_FindTask(char *p, int v);
extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);
extern u32 func_020307B0(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);

void BTLV_INPUT_DeleteTask(char *p, void *q)
{
    int i = BTLV_INPUT_FindTask(p, (int)q);
    int off;

    if (q != 0) {
        void *r = (void *)TCBL_GetTaskUserData(q);
        char *t = p + 0x28;
        void (*cb)(void *);

        off = i * 4;
        cb = *(void (**)(void *))(t + off);
        if (cb != 0)
            cb(q);
        if (r != 0)
            func_020307B0(r);
        func_02030EAC(q);
        *(int *)(p + off + 8) = 0;
        *(int *)(t + off) = 0;
    }
}
