/*
 * unit:     no
 * address:  0x02030A7C
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * function: sub_02030A7C
 *
 * BLOCKED, and not by anything another packet can fix: all 212 concrete
 * bytes are correct, but three ABS32 sites stay wildcarded because both
 * data symbols they name, the report record at 0x02146970 and the fallback
 * name string at 0x020A7824, appear in exactly one literal pool in the
 * whole image, this function's own. Plain data has only the `literal`
 * evidence class available to it, and `literal` needs the same word in a
 * pool at a different address; a `matched` entry cannot attest a data
 * address. Nothing in this packet or any other changes that, and
 * --suggest-split cannot cut a single function section. This is a
 * permanent MATCH unless the manifest grows a data-definition evidence
 * class.
 *
 * It blocks one thing downstream: src/pending/sub_02030B50.c, whose pool
 * word is this function's address and which therefore needs a `matched`
 * entry here.
 *
 * The per-block visitor sub_02030B50 hands to the heap walk sub_02060F50:
 * it fills a single global report record with one block's provenance, then
 * leaves its scratch buffer full of padding for a caller that no longer
 * exists.
 *
 *   void sub_02030A7C(void *hdr)
 *
 * The argument is the block header address, not the payload: the payload
 * is hdr + 0x1c and every other function in this family takes the payload,
 * which is why the first thing here is the `add r6, r4, #0x1c` that undoes
 * the difference before calling sub_020304C0.
 *
 * The report record at 0x02146970 is one struct, not three globals: the
 * u16 tag at +0, the payload pointer at +4, the block size at +8 and the
 * name at +0xc (0x0214697C, the address the second copy targets). Reading
 * the two pool words as separate objects would split one symbol in two and
 * lose a relocation
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 *
 * If sub_020308B8 rejects the stamped name, a 13-byte fallback string is
 * copied over the buffer from 0x020A7824 and the tag is reported as zero;
 * 0x020A7824 sits immediately after the watch id g_020A7820 in the same
 * data block.
 *
 * Two details of the tail:
 *
 *  - `strlen` is called twice on the same buffer with nothing between the
 *    calls but the `g.tag = tag` store. The store is to a `u16 *` that may
 *    alias the `char` buffer, so the first length cannot be reused and the
 *    second call is real, not a copy-paste artefact.
 *  - The padding loop then overwrites the *front* of the buffer with
 *    `0x12 - strlen(buf)` spaces and NUL-terminates there, after the name
 *    has already been copied out to the global. Nothing reads the result:
 *    it is the residue of a formatted print whose output argument the
 *    release build dropped. It must still be written out or the function
 *    is 40 bytes short.
 *
 * symbols:
 *   g_BlockReport   0x02146970  data
 *   g_020A7824      0x020A7824  data
 *   sub_020304C0    0x020304C0  arm
 *   sub_020308B8    0x020308B8  arm
 *   sub_0203F004    0x0203F004  arm
 *   sub_02060F90    0x02060F90  arm
 *   sub_02082D44    0x02082D44  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02030A7C.c \
 *       --func sub_02030A7C --addr 0x02030A7C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BlockReport {
    u16 tag;
    u16 pad02;
    void *ptr;
    u32 size;
    char name[0x14];
};

struct HeapBlockSite {
    char name[0x12];
    u16  tag;
};

extern struct BlockReport g_BlockReport;
extern char g_020A7824[13];

extern void *sub_020304C0(void *p);
extern int sub_020308B8(u8 *buf, const char *name);
extern u32 sub_0203F004(const char *s);
extern u32 sub_02060F90(void *block);
extern void sub_02082D44(const void *src, void *dest, u32 size);

void sub_02030A7C(void *hdr)
{
    u8 buf[0x14];
    struct HeapBlockSite *rec;
    void *payload;
    u16 tag;
    int pad;
    int i;

    payload = (char *)hdr + 0x1c;
    rec = (struct HeapBlockSite *)sub_020304C0(payload);
    g_BlockReport.size = sub_02060F90(hdr);
    g_BlockReport.ptr = payload;
    if (sub_020308B8(buf, rec->name) != 0) {
        tag = rec->tag;
    } else {
        sub_02082D44(g_020A7824, buf, 13);
        tag = 0;
    }
    sub_02082D44(buf, g_BlockReport.name, sub_0203F004((const char *)buf) + 1);
    g_BlockReport.tag = tag;
    pad = 0x12 - (int)sub_0203F004((const char *)buf);
    for (i = 0; i < pad; i++) {
        buf[i] = ' ';
    }
    buf[i] = 0;
}
