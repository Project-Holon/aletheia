/*
 * function: func_021C1F74
 * address: 0x021C1F74
 * packet: pkt_ov099_021C1F74
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00008.h"
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern void func_020307B0(void *);
typedef struct {
    char pad[0x8f8];
    void *windows[8];
    void *pairs[8][2];
} Work;
void func_021C1F74(char *p)
{
    int i;
    int j;
    for (i = 0; i < 8; i++) {
        func_020452E8(((Work *)p)->windows[i]);
        for (j = 0; j < 2; j++) func_020452E8(((Work *)p)->pairs[i][j]);
    }
    func_020452E8(((struct Obj00008 *)p)->f958);
    func_020452E8(((struct Obj00008 *)p)->f95C);
    func_020307B0(((struct Obj00008 *)p)->f8B4);
    func_020307B0(((struct Obj00008 *)p)->f8BC);
}
