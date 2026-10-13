/*
 * function: func_021B83E0
 * address: 0x021B83E0
 * packet: pkt_ov105_021B83E0
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte padding before func_021B8434
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
typedef struct { u32 objects[3]; u8 pad[0x24]; u8 digits[3]; u8 pad1; int state[3]; } Display;
void func_021B83E0(Display *p, int i)
{
    if (p->state[i] == 0) {
        if (i == 0 && p->digits[2 - i] == 0) {
            p->state[i] = 1;
            return;
        }
        if (i == 0 && p->digits[2 - i] == 0 && i == 1 && p->digits[2 - i] == 0) {
            p->state[i] = 1;
            return;
        }
        p->state[i] = 1;
        CLACT_SetActorDrawEnable((struct Obj *)p->objects[i], 1);
    }
}
