/*
 * function: func_0200A13C
 * address:  0x0200A13C
 * packet:   pkt_02009EDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200A13C.c \\
 *       --func func_0200A13C --addr 0x0200A13C --thumb --cc 1.1p1
 *
 * symbols:
 *   MYSTERY_DATA_CheckCardExist  0x02009F50  thumb
 *   MYSTERY_DATA_GetCardMax  0x0200A400  thumb
 *   MYSTERY_DATA_GetCardSlot  0x0200A43C  thumb
 *   MYSTERY_DATA_Encrypt  0x0200A480  thumb
 *   MYSTERY_DATA_Decrypt  0x0200A49C  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
extern u32  MYSTERY_DATA_GetCardMax(struct Obj *p);
extern void MYSTERY_DATA_Decrypt(struct Obj *p);
extern void *MYSTERY_DATA_GetCardSlot(struct Obj *p, u32 i);
extern void MYSTERY_DATA_Encrypt(struct Obj *p);
extern int MYSTERY_DATA_CheckCardExist(char *p, unsigned int idx);

void func_0200A13C(u8 *p, u32 i)
{
    u32 n = MYSTERY_DATA_GetCardMax((struct Obj *)p);
    u8 *q;

    MYSTERY_DATA_Decrypt((struct Obj *)p);
    if (i < n) {
        q = MYSTERY_DATA_GetCardSlot((struct Obj *)p, i);
        q[0xb4] |= 2;
    }
    MYSTERY_DATA_Encrypt((struct Obj *)p);
}
