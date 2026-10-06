/*
 * function: func_021B9E54
 * address:  0x021B9E54
 * packet:   pkt_ov088_021B9E54
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent (40) runs 2 bytes past the compiled function (38);
 *           trailing alignment padding, no byte difference.
 *
 * symbols:
 *   func_02011558  0x02011558  thumb
 *   func_02048AC4  0x02048AC4  arm
 *   func_02048C4C  0x02048C4C  arm
 *   func_020480E4  0x020480E4  arm
 *   func_02047E54  0x02047E54  arm
 */

typedef unsigned int   u32;
struct Ctx;
struct IcaAnime;
struct Rec;
extern void func_02011558(struct IcaAnime *p);
extern u32 func_02048AC4(void *ptr);
extern void func_02048C4C(int);
extern void func_020480E4(struct Ctx *c, u32 i);
extern void func_02047E54(struct Rec *p);

void func_021B9E54(int *p)
{
    func_02011558((struct IcaAnime *)p[3]);
    func_02048AC4((void *)p[4]);
    func_02048C4C(p[2]);
    func_020480E4((struct Ctx *)p[0], ((unsigned short *)p)[2]);
    func_02047E54((struct Rec *)p[0]);
}
