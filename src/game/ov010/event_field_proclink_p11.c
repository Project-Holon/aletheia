/*
 * file:     event_field_proclink_p11.c
 * unit:     yes
 * function: func_02161CDC
 * address: 0x02161CDC
 * packet: pkt_ov010_02161CDC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F4CC 0x0203F4CC arm
 *   func_0202E888 0x0202E888 thumb
 *   func_02161C84 0x02161C84 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned u32;
typedef struct { u32 hour, minute, second; } RtcTime;
typedef struct { u32 a,b,c; u8 d,e,f; u8 g:7; u8 h:1; } S;
struct RtcTime;
extern void func_0203F4CC(struct RtcTime *time);
extern u8 func_0202E888(void);
extern void func_02161C84(S *, int, int, u8, u32, u8, u8, u8);
void func_02161CDC(S *s, int a, int b, u8 d)
{
    RtcTime time;
    u8 day;
    func_0203F4CC((struct RtcTime *)(&time));
    day = func_0202E888();
    func_02161C84(s, a, b, d, 0, time.hour, time.minute, day);
}
