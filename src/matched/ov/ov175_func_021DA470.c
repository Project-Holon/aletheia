/*
 * function: func_021DA470
 * address: 0x021DA470
 * packet: pkt_ov175_021DA470
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * stack: four date words (including weekday), three time words.
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_0200FA84 0x0200FA84 thumb
 *   func_02167ED8 0x02167ED8 arm ov009
 *   func_02082BCC 0x02082BCC arm
 */
extern int func_0203CD98(void);
extern void func_0200FA84(void);
extern int func_02167ED8(int *, int *);
extern void func_02082BCC(void *, int, int);
void func_021DA470(unsigned char *dest)
{
    int date[4];
    int time[3];
    if (!func_0203CD98()) func_0200FA84();
    if (!func_02167ED8(date, time)) func_0200FA84();
    func_02082BCC(dest, 0, 6);
    dest[0] = date[0];
    dest[1] = date[1];
    dest[2] = date[2];
    dest[3] = time[0];
    dest[4] = time[1];
    dest[5] = time[2];
}
