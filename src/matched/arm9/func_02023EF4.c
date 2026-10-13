/*
 * unit:     no
 * function: BRIGHTNESS_ChangeRequest
 * address:  0x02023EF4
 * packet:   pkt_02023EF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Front end for BRIGHTNESS_ChangeInit: given a record pointer and a two-bit engine
 * mask, it arms the record once per selected engine. Each arm first sets
 * the hardware blend-brightness register for that engine to the starting
 * value through G2x_SetBlendBrightness_ (0x0207D658), then calls
 * BRIGHTNESS_ChangeInit with the shared step/from/to triple and the two stack
 * arguments (the starting value, and the engine bit itself as the tag).
 *
 * The two pool words 0x04000050 and 0x04001050 are the main and sub
 * engine's BLDCNT/BLDY block; both arms are written out in full rather
 * than factored behind a helper, which is what keeps them as two separate
 * call sequences rather than one tail-merged site.
 *
 * Note the second engine's register word is the plain constant 0x04001050
 * in the pool, not 0x04000050 + 0x1000 computed at run time.
 *
 * RESOLVED 2026-09-21 (wave3 wipe_sub). This file sat in src/pending at
 * MATCH with the note below blaming a missing `literal` witness for the two
 * ABS32 pool words. The blocker was not evidentiary: the symbols block named
 * the tables at 0x0202691C and 0x020268FC, but the ROM pool words at
 * 0x02023F54 and 0x02023F5C are 0x0214691C and 0x021468FC. Because a MATCH
 * wildcards the relocation field, the wrong address was never compared and
 * the typo read as an attestation failure. With the real addresses both
 * sites resolve as `literal` (6 and 12 witnesses image-wide, e.g. the pool
 * words at 0x02023FCC and 0x02023FD0 in the neighbouring unit) and the
 * function is EXACT. Earlier prose, kept for the record:
 *
 * [stale] capped at MATCH; blocking evidence class literal; neither word
 * appears in any literal pool at another address. -- wrong on both counts,
 * see above.
 *
 * Both engines pass the same record pointer p to BRIGHTNESS_ChangeInit; the first
 * argument is the engine's own descriptor table, and the last argument is
 * the engine bit (1 or 2), which BRIGHTNESS_ChangeInit stores to f04.
 *
 * G2x_SetBlendBrightness_ takes three arguments (addr, plane, brightness)
 * and both arms pass all three. The first arm emits no `mov r2` because
 * `from` is still live in r2 from entry; the second arm reloads it from r6
 * after the intervening call. An earlier spelling declared a two-argument
 * extern for the first arm, which matched the bytes but left r2 unnamed
 * (docs/idioms/an-argument-passed-through-a-register-must-be-named-in-the-c.md).
 *
 * symbols:
 *   G2x_SetBlendBrightness_   0x0207D658  arm
 *   BRIGHTNESS_ChangeInit             0x02023E9C  thumb
 *   data_0214691C             0x0214691C  data
 *   data_021468FC             0x021468FC  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void BRIGHTNESS_ChangeInit(void *rec, void *p, u16 steps, s16 from,
                          u32 a4, u32 a5);

extern char data_0214691C[];
extern char data_021468FC[];

void BRIGHTNESS_ChangeRequest(void *p, u16 steps, s16 from, s16 to, u32 mask)
{
    if (p == 0) {
        return;
    }

    if (mask & 1) {
        G2x_SetBlendBrightness_(0x04000050, to, from);
        BRIGHTNESS_ChangeInit(data_0214691C, p, steps, from, (u32)to, 1);
    }

    if (mask & 2) {
        G2x_SetBlendBrightness_(0x04001050, to, from);
        BRIGHTNESS_ChangeInit(data_021468FC, p, steps, from, (u32)to, 2);
    }
}
