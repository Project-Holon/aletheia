/*
 * function: FIELD_GIMMICK_SOUND_OBJS_StartWait
 * address: 0x021F3A38
 * packet: pkt_ov053_021F3A38
 * region: ov053
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: Inline random call keeps the returned value on the right of the add.
 *       The final two bytes of the handed extent are alignment padding.
 * symbols:
 *   func_02005728 0x02005728 thumb
 */
extern unsigned func_02005728(unsigned);
void FIELD_GIMMICK_SOUND_OBJS_StartWait(char *a, int i)
{
    ((int *)(a + 0x1c))[i] = ((int *)(a + 0x30))[i] +
        func_02005728(((int *)(a + 0x44))[i] - ((int *)(a + 0x30))[i] + 1);
}
