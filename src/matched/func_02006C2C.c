/*
 * unit:     no
 * function: func_02006C2C
 * address:  0x02006C2C
 * packet:   pkt_02006C2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   func_02007B50  0x02007B50  thumb
 *   func_02007B64  0x02007B64  thumb
 *   func_02007B68  0x02007B68  thumb
 *   func_02048F4C  0x02048F4C  arm
 *
 * The reader for a/1/9/4, the per-species cry parameter table.  It sits in
 * pm_voice.c (the __FILE__ strings either side of it in the image are
 * pm_voice.c at 0x020066E0 and snd_mic.c at 0x02006D2C), and it is the only
 * call site in the whole image that loads archive id 194.
 *
 * func_02048F4C(dst, archive_id, member) copies one member into a
 * caller-supplied buffer, and here the buffer is four bytes, matching
 * a/1/9/4's 652 fixed 4-byte records.  Only the halfword at +2 is used:
 * its low byte is written to *cryPitch, and the value's range over the
 * whole archive is 97..127, i.e. a 7-bit playback parameter.  The u16 at
 * +0 is not touched by this function.
 *
 * The member index is the species id, which the special case pins down
 * exactly: `species == 441` is Chatot, the one species whose cry is a
 * recorded sample rather than a played bank note.  441 is rematerialised
 * as 194 + 247 off the register that already holds the archive id
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md),
 * which is why the same literal appears twice in the C and once in the
 * bytes.  On that path the two sample-rate outputs are overwritten with
 * 0x1FF4, the pitch byte with 0x78 = 120 (inside the table's own 97..127
 * range), and the third output with func_020056EC(0x2000) + 0x8000.
 *
 * Content constant note: 441 is a national species id and 652 is the
 * record count of Black's a/1/9/4.  Neither is expected to move in White,
 * but both are data-side numbers, so they are called out here rather than
 * assumed shared.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006C2C.c \
 *       --func func_02006C2C --addr 0x02006C2C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32   func_020056EC(u32 x);
extern u32   func_02007B50(void *p);
extern void *func_02007B64(void *p);
extern u32   func_02007B68(void *p, void *q);
extern void  func_02048F4C(void *dst, u32 archive_id, u32 member);

u32 func_02006C2C(u32 species, u32 form, void **rec, void **owner,
                  u32 *rate1, u32 *rate2, u32 *addr, u8 *cryPitch)
{
    u16 entry[2];

    func_02048F4C(entry, 194, species);
    *cryPitch = (u8)entry[1];
    if (rec == 0) {
        return 0;
    }
    if (species == 441 && form == 0 && func_02007B50(rec[0]) == 1) {
        func_02007B68(owner[0], func_02007B64(rec[0]));
        *rate1 = 0x1FF4;
        *rate2 = 0x1FF4;
        *cryPitch = 0x78;
        *addr = func_020056EC(0x2000) + 0x8000;
        return 1;
    }
    return 0;
}
