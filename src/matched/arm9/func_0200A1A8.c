/*
 * unit:     no
 * function: MYSTERY_DATA_IsEventFlag
 * address:  0x0200A1A8
 * packet:   pkt_0200A170
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MYSTERY_DATA_GetEventFlags  0x0200A41C  thumb
 *   MYSTERY_DATA_Encrypt  0x0200A480  thumb
 *   MYSTERY_DATA_Decrypt  0x0200A49C  thumb
 */

struct Obj;
extern void *MYSTERY_DATA_GetEventFlags(struct Obj *p);
extern void MYSTERY_DATA_Decrypt(struct Obj *p);
extern void MYSTERY_DATA_Encrypt(struct Obj *p);
int MYSTERY_DATA_IsEventFlag(char *p, unsigned int bit)
{
    int r = 0;
    unsigned char *t = (unsigned char *)MYSTERY_DATA_GetEventFlags((struct Obj *)p);
    MYSTERY_DATA_Decrypt((struct Obj *)p);
    if (bit < 0x800) {
        if (t[bit >> 3] & (1 << (bit & 7)))
            r = 1;
    }
    MYSTERY_DATA_Encrypt((struct Obj *)p);
    return r;
}
