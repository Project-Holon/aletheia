/*
 * function: WIFIBATTLEMATCH_NET_AddMatchKey
 * address:  0x021DA4B8
 * packet:   pkt_021DA4B8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8         0x02082D44  arm
 *   DWC_AddMatchKeyInt  0x0216C8DC  arm  ov009
 *   d_021E2E10          0x021E2E10  data
 *
 * Registers match key i: stores the value, copies the three-byte key name from the table at 0x021E2E10, and keeps the key id DWC_AddMatchKeyInt returns.
 */

typedef unsigned char u8;
typedef unsigned long u32;

struct MatchKey {
    int  value;
    u8   id;
    u8   pad_05;
    char name[3];
    u8   term;
    u8   pad_0a[2];
};

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u8 DWC_AddMatchKeyInt(u8 keyID, const char *keyString, const int *valueSrc);
extern const char *const d_021E2E10[];

void WIFIBATTLEMATCH_NET_AddMatchKey(char *obj, int i, int value)
{
    struct MatchKey *k = (struct MatchKey *)(obj + 0xc4) + i;

    k->value = value;
    MI_CpuCopy8(d_021E2E10[i], k->name, 3);
    k->term = 0;
    k->id = DWC_AddMatchKeyInt(k->id, k->name, &k->value);
}
