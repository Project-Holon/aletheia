/*
 * function: MYSTERY_DATA_SwapCards
 * address:  0x0200A254
 * packet:   pkt_0200A1E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MYSTERY_DATA_CheckCardExist  0x02009F50  thumb
 *   MYSTERY_DATA_GetCardPtr  0x02009FD4  thumb
 *   MYSTERY_DATA_Encrypt  0x0200A480  thumb
 *   MYSTERY_DATA_Decrypt  0x0200A49C  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 */

struct Obj;
extern void MYSTERY_DATA_Decrypt(struct Obj *obj);
extern void MYSTERY_DATA_Encrypt(struct Obj *obj);
extern int MYSTERY_DATA_CheckCardExist(char *p, unsigned int idx);
extern void *MYSTERY_DATA_GetCardPtr(char *p, unsigned int idx);
extern void MI_CpuCopy8(void *src, void *dst, int n);
void MYSTERY_DATA_SwapCards(void *p, unsigned int a, unsigned int b)
{
    unsigned char tmp[0xcc];
    MYSTERY_DATA_Decrypt(p);
    if (MYSTERY_DATA_CheckCardExist(p, a) && MYSTERY_DATA_CheckCardExist(p, b)) {
        void *x = MYSTERY_DATA_GetCardPtr(p, a);
        void *y = MYSTERY_DATA_GetCardPtr(p, b);
        MI_CpuCopy8(x, tmp, 0xcc);
        MI_CpuCopy8(y, x, 0xcc);
        MI_CpuCopy8(tmp, y, 0xcc);
    }
    MYSTERY_DATA_Encrypt(p);
}
