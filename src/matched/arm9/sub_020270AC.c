/*
 * function: GAME_BEACON_CopyStrbufCodes
 * address:  0x020270AC
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   STRBUF_ToChars       0x02045A38  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 STRBUF_GetEosChar(void);
struct U16Vec;
extern void STRBUF_ToChars(struct U16Vec *vec, u16 *out, u32 n);

void GAME_BEACON_CopyStrbufCodes(void *vec, u16 *dest)
{
    u16 buf[12];
    u16 stamp;
    int i;

    stamp = STRBUF_GetEosChar();
    STRBUF_ToChars(vec, buf, 12);

    for (i = 0; i < 10; i++) {
        dest[i] = buf[i];
        if (stamp == buf[i]) {
            break;
        }
    }
}
