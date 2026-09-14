/*
 * unit:     no
 * address:  0x02030880
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02030880
 *
 * Success-side bookkeeping for the allocation entry point sub_02030734:
 * stamps the allocation-site provenance pair (name string, u16 tag) into
 * the block header of a freshly allocated payload.
 *
 *   void sub_02030880(void *p, const char *site, u16 tag)
 *
 * sub_020304C0 (already EXACT) converts the payload pointer into
 * `&((char *)p - 0x1c)[4]`, so the provenance record lives at header+4 and
 * is 0x14 bytes wide: an 0x12-byte name field followed by the u16 tag at
 * +0x12. The copy is a bounded strncpy-shaped loop that stops on the NUL
 * but, like strncpy with a full-length source, does not NUL-terminate: the
 * terminator is only written because it is copied.
 *
 * The single `ldrsb` per iteration (not two loads) is the tell that the
 * source byte is bound to a local before being both stored and tested;
 * writing `dst[i] = site[i]; if (site[i] == 0)` would reload, since a
 * `const char *` source may alias the `char *` destination.
 *
 * symbols:
 *   sub_020304C0    0x020304C0  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030880.c \
 *       --func sub_02030880 --addr 0x02030880 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

struct HeapBlockSite {
    char name[0x12];
    u16  tag;
};

extern void *sub_020304C0(void *p);

void sub_02030880(void *p, const char *site, u16 tag)
{
    struct HeapBlockSite *rec;
    int i;

    rec = (struct HeapBlockSite *)sub_020304C0(p);
    for (i = 0; i < 0x12; i++) {
        char c = site[i];
        rec->name[i] = c;
        if (c == 0) {
            break;
        }
    }
    rec->tag = tag;
}
