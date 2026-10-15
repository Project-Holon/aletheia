/*
 * function: BOX2_SEQ_StateSetMenu
 * address: 0x021E22E0
 * packet: pkt_ov170_021E22E0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   BOX2_SEQ_PrintPromptB 0x021EBCB4 thumb ov170
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb ov170
 */
#include "../include/Obj06548.h"
#include "../include/Obj23889.h"
#include "../include/Obj23890.h"
#include "../include/Obj23891.h"
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void BOX2_SEQ_PrintPromptB(unsigned char *, int, int);
extern void BOX2_SEQ_PrintPrompt(unsigned char *, int, int, int);
int BOX2_SEQ_StateSetMenu(unsigned char *p)
{
    func_020307B0(((struct Obj23889 *)(*(char * *)&((struct Obj06548 *)p)->f2C))->f60);
    if ((*(unsigned char **)(p + 0x2C))[0xA172] == 1) {
        if (((struct Obj23890 *)(*(char * *)&((struct Obj06548 *)p)->f0))->f24 == 3) {
            if (((struct Obj23891 *)(*(char * *)&((struct Obj06548 *)p)->f2C))->fA16C == 0)
                BOX2_SEQ_PrintPromptB(p, 0, 0x18);
            else
                BOX2_SEQ_PrintPromptB(p, 1, 0x18);
        } else {
            BOX2_SEQ_PrintPrompt(p, p[0x16], 1, 0x18);
        }
        (*(char **)(p + 0x2C))[0xA172] = 0;
    }
    return ((struct Obj06548 *)p)->f28;
}
