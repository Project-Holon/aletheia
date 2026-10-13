/*
 * function: MYSTERY_DATA_HasCardSpace
 * address:  0x0200A0C8
 * packet:   pkt_02009EDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MYSTERY_DATA_HasCardSpace.c \\
 *       --func MYSTERY_DATA_HasCardSpace --addr 0x0200A0C8 --thumb --cc 1.1p1
 *
 * symbols:
 *   MYSTERY_DATA_CheckCardSpace  0x02009F1C  thumb
 *   MYSTERY_DATA_Encrypt  0x0200A480  thumb
 *   MYSTERY_DATA_Decrypt  0x0200A49C  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
extern void MYSTERY_DATA_Decrypt(struct Obj *p);
extern int MYSTERY_DATA_CheckCardSpace(void *a0);
extern void MYSTERY_DATA_Encrypt(struct Obj *p);

u32 MYSTERY_DATA_HasCardSpace(u8 *p)
{
    u32 r;

    MYSTERY_DATA_Decrypt((struct Obj *)p);
    r = MYSTERY_DATA_CheckCardSpace(p);
    MYSTERY_DATA_Encrypt((struct Obj *)p);
    return r;
}
