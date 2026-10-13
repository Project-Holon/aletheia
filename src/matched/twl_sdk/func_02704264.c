/*
 * function: FATFSi_WaitForRequest
 * address:  0x02704264
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   DAT_02734428   0x02734428  data twl
 *   DAT_02734420   0x02734420  data twl
 *   func_02087988  0x02087988  arm twl
 *   func_020879EC  0x020879EC  arm twl
 *   func_02088688  0x02088688  arm twl
 *   func_02004490  0x02004490  thumb twl
 *   func_020857B0  0x020857B0  arm twl
 *   func_0208799C  0x0208799C  arm twl
 *   DAT_0273444c   0x0273444c  data twl
 */

typedef unsigned int u32;

typedef struct FsNode {
    u32 f00[3];
    struct FsNode *next;
} FsNode;

extern FsNode *DAT_02734428;
extern u32 DAT_02734420[];
extern u32 func_02087988(void);
extern u32 func_020879EC(void);
extern void func_02088688(void);
extern void func_02004490(u32);
extern void func_020857B0(u32 *);
extern void func_0208799C(u32);
extern u32 DAT_0273444c[];

void FATFSi_WaitForRequest(FsNode *a0) {
    u32 busy = 1;
    while ((busy != 0) ? 1 : 0) {
        u32 ime = func_02087988();
        /* the list is shared: every access rereads it */
        FsNode * volatile *pp = &DAT_02734428;
        FsNode *p;
        while (((p = *pp) != 0) ? 1 : 0) {
            if (*pp == a0) {
                busy = 0;
                *pp = (*pp)->next;
                a0->next = 0;
                break;
            }
            pp = &(*pp)->next;
        }
        if (busy != 0) {
            if (func_020879EC() == 0x12) {
                func_02088688();
                func_02004490(10000);
            } else {
                func_020857B0(DAT_02734420);
            }
        }
        func_0208799C(ime);
    }
}
