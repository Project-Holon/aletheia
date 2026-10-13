/*
 * function: SCRCMD_POKEMON_FLD_PrepareGiftReceiveMessage
 * address:  0x021B6D30
 * packet:   pkt_ov021_021B6D30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb ov010
 *   d_021D9980     0x021D9980  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int (*fn)(void *, void *, void *);
    u8 pad[0x14];
} Entry;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetWordSet(void *);
extern Entry d_021D9980[];

int SCRCMD_POKEMON_FLD_PrepareGiftReceiveMessage(int idx, void *x, void *c)
{
    void *r;
    int (*fn)(void *, void *, void *);

    r = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(c));
    fn = d_021D9980[idx].fn;
    if (x != 0 && fn != 0) {
        return fn(r, x, c);
    }
    return 7;
}
