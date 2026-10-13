/*
 * unit:     no
 * function: PLAYER_VOLUME_FADER_Create
 * address:  0x02028760
 * packet:   pkt_02028590
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLAYER_VOLUME_FADER_Init  0x020287B4  thumb
 */

extern void *func_02030734(unsigned int a, unsigned int size, int b, const char *name, unsigned short line);
struct Fader;
extern void PLAYER_VOLUME_FADER_Init(struct Fader *s);
void *PLAYER_VOLUME_FADER_Create(void *a, int v)
{
    char *p = (char *)func_02030734((unsigned int)a, 0xa, 0, (const char *)0x020A7500, 0x42);
    PLAYER_VOLUME_FADER_Init((struct Fader *)p);
    *p = (char)v;
    return p;
}
