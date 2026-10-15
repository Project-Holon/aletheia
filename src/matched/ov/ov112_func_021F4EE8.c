/*
 * function: MUSICAL_MCSS_SetElemFlag
 * address: 0x021F4EE8
 * packet: pkt_ov112_021F4EE8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: wide int argument into u16 bitfield preserves the redundant
 * halfword narrowing pair; a u16 argument produced 16 bytes, DIFF10.
 * leaf: sole overlay blocker of handed ov133 021B8140; explicit unused r0
 * retained from the caller. Twenty-byte body; following getter omitted.
 */
typedef unsigned short u16;
typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags;
void MUSICAL_MCSS_SetElemFlag(int unused,Flags *s,int flag)
{
    s->flag=flag;
}
