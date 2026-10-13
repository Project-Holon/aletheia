/*
 * unit:     no
 * function: MYSTERY_DATA_HasAnyCard
 * address:  0x0200A170
 * packet:   pkt_0200A170
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MYSTERY_DATA_CheckCardExist  0x02009F50  thumb
 *   MYSTERY_DATA_GetCardMax  0x0200A400  thumb
 *   MYSTERY_DATA_Encrypt  0x0200A480  thumb
 *   MYSTERY_DATA_Decrypt  0x0200A49C  thumb
 */

struct Obj;
extern unsigned int MYSTERY_DATA_GetCardMax(struct Obj *obj);
extern void MYSTERY_DATA_Decrypt(struct Obj *obj);
extern void MYSTERY_DATA_Encrypt(struct Obj *obj);
extern int MYSTERY_DATA_CheckCardExist(char *p, unsigned int idx);
int MYSTERY_DATA_HasAnyCard(char *p)
{
    int found = 0;
    unsigned int i;
    unsigned int n = MYSTERY_DATA_GetCardMax((struct Obj *)p);
    MYSTERY_DATA_Decrypt((struct Obj *)p);
    for (i = 0; i < n; i++) {
        if (MYSTERY_DATA_CheckCardExist(p, i) == 1)
            found = 1;
    }
    MYSTERY_DATA_Encrypt((struct Obj *)p);
    return found;
}
