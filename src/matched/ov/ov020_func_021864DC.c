/*
 * function: FIELD_WFBC_DATA_LOCAL_ApplyTalkedMoodBonus
 * address: 0x021864DC
 * packet: pkt_ov020_021864DC
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 66 bytes of code followed by two zero alignment bytes.
 * Lever: the inline helper holds the loaded byte in a full-width unsigned
 * local before clearing its bits; the constant argument stays positive
 * and is hoisted to a spill instead of folding to the byte complement.
 * symbols:
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid 0x02161ECC thumb ov010
 *   FIELD_WFBC_DATA_LOCAL_AddMood 0x02186BB8 thumb ov020
 */
typedef unsigned char u8;
extern int EVENT_FIELD_PROCLINK_IsReturnEntryValid(void *p);
extern int FIELD_WFBC_DATA_LOCAL_AddMood(u8 *p, int a);

static inline void clear_flag(u8 *p, unsigned int mask)
{
    unsigned int value = *p;
    value &= ~mask;
    *p = value;
}

void FIELD_WFBC_DATA_LOCAL_ApplyTalkedMoodBonus(u8 *p)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(p + 8 + i * 0x18) &&
            (*(u8 *)((unsigned int)p + i * 0x18 + 0xb) & 2)) {
            FIELD_WFBC_DATA_LOCAL_AddMood(p + 8 + i * 0x18, 3);
            clear_flag((u8 *)((unsigned int)p + i * 0x18 + 0xb), 2);
        }
    }
}
