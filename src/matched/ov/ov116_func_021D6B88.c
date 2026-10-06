/*
 * function: func_021D6B88
 * address: 0x021D6B88
 * packet: pkt_ov116_021D6B88
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D6C4E follow the epilogue.
 * evidence: 0217BC44's full ov009 ARM wrapper forwards r0-r3 and
 * three full-word stack arguments to 0217B828; this caller supplies all7.
 * symbols:
 *   func_02012944 0x02012944 thumb
 *   func_02008494 0x02008494 thumb
 *   func_02008510 0x02008510 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_02045A90 0x02045A90 arm
 *   func_020458F8 0x020458F8 arm
 *   func_02045A98 0x02045A98 arm
 *   func_0217BC44 0x0217BC44 arm ov009
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj04469.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_02012944(void *);
extern void func_02008494(void *, void *);
extern void *func_02008510(void *, int);
extern void func_02082BCC(void *, u8, u32);
struct U16Vec;
extern u16 *func_02045A90(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
extern u16 func_02045A98(void);
extern int func_0217BC44(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region);
extern void func_02045808(struct U16Vec *vec);
void func_021D6B88(u8 *p, void *save, int id)
{
    void *str;
    u16 *chars;
    u32 i;
    func_02008494(func_02012944(save), ((struct Obj04469 *)p)->f218);
    str = func_02008510(((struct Obj04469 *)p)->f218, id);
    func_02082BCC(p + 0x1f0, 0, 40);
    ((struct Obj04469 *)p)->f214 = id;
    chars = func_02045A90(str);
    for (i = 0; i < func_020458F8(str) + 1u; i++) {
        u16 c = chars[i];
        if (c == func_02045A98()) ((u16 *)(p + 0x1f0))[i] = 0;
        else ((u16 *)(p + 0x1f0))[i] = c;
    }
    ((struct Obj04469 *)p)->f208 = p + 0x1f0;
    ((struct Obj04469 *)p)->f210 = 0;
    func_0217BC44((short unsigned int **)(p + 0x208), 1, 0, 0, (char *)(p + 0x20c), (int *)(p + 0x210), 128);
    func_02045808(str);
}
