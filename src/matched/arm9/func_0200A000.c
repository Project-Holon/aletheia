/*
 * unit:     no
 * function: MYSTERY_DATA_GetCard
 * address:  0x0200A000
 * packet:   pkt_02009F1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MYSTERY_DATA_GetCardPtr  0x02009FD4  thumb
 *   MYSTERY_DATA_GetCardMax  0x0200A400  thumb
 *   MYSTERY_DATA_Encrypt  0x0200A480  thumb
 *   MYSTERY_DATA_Decrypt  0x0200A49C  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 */

struct Obj;
extern unsigned int MYSTERY_DATA_GetCardMax(struct Obj *p);
extern void MYSTERY_DATA_Decrypt(struct Obj *p);
extern void MYSTERY_DATA_Encrypt(struct Obj *p);
extern void *MYSTERY_DATA_GetCardPtr(char *p, unsigned int idx);
extern void MI_CpuCopy8(void *dst, void *src, int n);
int MYSTERY_DATA_GetCard(char *p, int idx, void *buf)
{
    char *e;
    int r = 0;
    MYSTERY_DATA_GetCardMax((struct Obj *)p);
    MYSTERY_DATA_Decrypt((struct Obj *)p);
    e = (char *)MYSTERY_DATA_GetCardPtr(p, idx);
    if (e != 0) {
        MI_CpuCopy8(e, buf, 0xcc);
        r = 1;
    }
    MYSTERY_DATA_Encrypt((struct Obj *)p);
    return r;
}
