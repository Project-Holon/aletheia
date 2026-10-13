/*
 * function: func_021F1F9C
 * address:  0x021F1F9C
 * packet:   pkt_ov032_021F1F9C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1F9C 0x021F1F9C thumb
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj02752.h"
#include "../include/Obj20443.h"
#include "../include/Obj20444.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Chan02021FD8;
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);

void func_021F1F9C(void *task, u8 *s)
{
    u8 c = s[0];

    if (c < 2) {
        if (s[1]++ >= s[2]) {
            PALANM_BlendChannel((struct Chan02021FD8 *)(((struct Obj20443 *)(*(char * *)&((struct Obj02752 *)s)->fC))->fAC), 3, s[3], 0x10, (c % 2) << 2, 0x7fff);
            s[0]++;
            s[1] = 0;
        }
    } else {
        int *r;

        PALANM_BlendChannel((struct Chan02021FD8 *)(((struct Obj20444 *)(*(char * *)&((struct Obj02752 *)s)->fC))->fAC), 3, s[3], 0x10, 0, 0x7fff);
        r = *(int * *)&((struct Obj02752 *)s)->f10;
        if (r != 0)
            (*r)--;
        TCBL_DeleteTask(task);
    }
}
