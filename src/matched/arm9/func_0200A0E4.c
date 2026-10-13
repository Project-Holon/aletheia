/*
 * function: func_0200A0E4
 * address:  0x0200A0E4
 * packet:   pkt_02009EDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200A0E4.c \\
 *       --func func_0200A0E4 --addr 0x0200A0E4 --thumb --cc 1.1p1
 *
 * symbols:
 *   MYSTERY_DATA_CheckCardExist  0x02009F50  thumb
 *   MYSTERY_DATA_Encrypt  0x0200A480  thumb
 *   MYSTERY_DATA_Decrypt  0x0200A49C  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
extern void MYSTERY_DATA_Decrypt(struct Obj *p);
extern int MYSTERY_DATA_CheckCardExist(char *p, unsigned int idx);
extern void MYSTERY_DATA_Encrypt(struct Obj *p);

u32 func_0200A0E4(u8 *p, u32 a)
{
    u32 r;

    MYSTERY_DATA_Decrypt((struct Obj *)p);
    r = MYSTERY_DATA_CheckCardExist((char *)p, a);
    MYSTERY_DATA_Encrypt((struct Obj *)p);
    return r;
}
