/*
 * function: func_021FE2F8
 * address: 0x021FE2F8
 * packet: pkt_ov186_021FE2F8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_020A1B38 0x020A1B38 data a2
 */
extern const short d_020A1B38[];
int func_021FE2F8(char *p, int *out, int step)
{
    unsigned short angle_delta;
    signed char direction;
    int angle;
    int initial_angle;
    int duration;
    unsigned short initial_radius;
    int radius_delta;
    int radius, x, y;
    initial_angle = *(unsigned short *)(p + 0x14);
    angle_delta = *(unsigned short *)(p + 0x16) - initial_angle;
    initial_radius = *(unsigned short *)(p + 0x10);
    radius_delta = (short)(*(short *)(p + 0x12) - (short)initial_radius);
    direction = radius_delta / (radius_delta < 0 ? -radius_delta : radius_delta);
    duration = *(int *)(p + 0x18);
    angle = (unsigned short)(initial_angle + angle_delta * step / duration);
    if (radius_delta < 0) radius_delta = -radius_delta;
    radius = initial_radius + direction * (step * radius_delta / duration);
    if (radius < 0) radius = 0;
    x = (d_020A1B38[(angle >> 4) * 2 + 1] * radius) >> 12;
    y = (d_020A1B38[(angle >> 4) * 2] * radius) >> 12;
    x += *(int *)p;
    y += *(int *)(p + 4);
    *(int *)(p + 8) = x;
    *(int *)(p + 12) = y;
    if (out) { out[0] = x; out[1] = y; }
    return step == *(int *)(p + 0x18);
}
