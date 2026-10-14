/*
 * function: GURU2_MAIN_BlendFadeTask
 * address: 0x021E1540
 * packet: pkt_ov137_021E1540
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_BlendPalette 0x021DFF20 thumb ov137
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 */
typedef unsigned char  u8;
struct Node;
extern void GURU2_MAIN_BlendPalette(u8 *p, int a);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
void GURU2_MAIN_BlendFadeTask(void *task, int *p)
{
    int done = 0;
    if (p[1] == 1) {
        p[2]--;
        if (p[2] <= 0) {
            p[2] = 0;
            done = 1;
        }
    } else {
        p[2]++;
        if (p[2] >= 8) {
            p[2] = 8;
            done = 1;
        }
    }
    GURU2_MAIN_BlendPalette((void *)p[0], p[2]);
    if (done == 1) {
        func_020307B0(p);
        func_02030EAC(task);
    }
}
