/*
 * unit: yes
 * function: BTL_WAZAREC_Add,BTL_WAZAREC_SetEffectiveLast,BTL_WAZAREC_IsUsedWaza,BTL_WAZAREC_GetUsedWazaCount,BTL_WAZAREC_GetEffectiveWaza
 * address: 0x0689D01C
 * packet: pkt_ov095_0689D01C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: common post-loop return blocks and declaration order recover the saved registers.
 * extent: code after handed ARM veneer 0689D014; parent cleared all members.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 value; u16 kind; u8 data, flag; } Rec;
typedef struct { u32 pos; Rec r[120]; } O;
void BTL_WAZAREC_Add(O *p, u32 kind, u32 value, u32 data)
{
    p->r[p->pos].kind = kind;
    p->r[p->pos].value = value;
    p->r[p->pos].data = data;
    p->r[p->pos].flag = 0;
    p->pos++;
    if (p->pos >= 120)
        p->pos = 0;
}
void BTL_WAZAREC_SetEffectiveLast(O *p)
{
    int i;
    i = p->pos - 1;
    if (i < 0) i = 119;
    p->r[i].flag = 1;
}
int BTL_WAZAREC_IsUsedWaza(O *p, u32 kind, u32 value)
{
    int i;
    int end;
    end = p->pos;
    i = end;
    for (;;) {
        i--;
        if (i < 0) i = 119;
        if (i == end || p->r[i].kind == 0)
            break;
        if (kind == p->r[i].kind && value == p->r[i].value)
            return 1;
    }
    return 0;
}
int BTL_WAZAREC_GetUsedWazaCount(O *p, u32 kind, u32 value)
{
    int i;
    int count;
    int end;
    end = p->pos;
    count = 0;
    i = end;
    for (;;) {
        i--;
        if (i < 0) i = 119;
        if (i == end || p->r[i].kind == 0)
            break;
        if (kind == p->r[i].kind && value == p->r[i].value)
            count++;
    }
    return count;
}
u16 BTL_WAZAREC_GetEffectiveWaza(O *p, u32 value)
{
    int i;
    int end;
    u16 kind;
    end = p->pos;
    i = end;
    for (;;) {
        i--;
        if (i < 0) i = 119;
        if (i == end)
            break;
        kind = p->r[i].kind;
        if (kind == 0)
            break;
        if (p->r[i].flag != 0 && value == p->r[i].value)
            return kind;
    }
    return 0;
}
