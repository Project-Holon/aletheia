/*
 * function: MYSTERY_DATA_SetEventFlag
 * address:  0x0200A1E4
 * packet:   pkt_0200A1E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MYSTERY_DATA_GetEventFlags  0x0200A41C  thumb
 *   MYSTERY_DATA_Encrypt  0x0200A480  thumb
 *   MYSTERY_DATA_Decrypt  0x0200A49C  thumb
 */

typedef unsigned char u8;
struct Obj;
extern void *MYSTERY_DATA_GetEventFlags(struct Obj *obj);
extern void MYSTERY_DATA_Decrypt(struct Obj *obj);
extern void MYSTERY_DATA_Encrypt(struct Obj *obj);
void MYSTERY_DATA_SetEventFlag(void *p, unsigned int idx)
{
    u8 *b = MYSTERY_DATA_GetEventFlags(p);
    MYSTERY_DATA_Decrypt(p);
    if (idx < 0x800) {
        b[idx >> 3] |= (u8)(1 << (idx & 7));
    }
    MYSTERY_DATA_Encrypt(p);
}
