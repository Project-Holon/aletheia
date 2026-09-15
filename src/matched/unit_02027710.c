/*
 * unit:     yes
 * function: func_02027710, func_02027714, func_02027718, func_0202771C,
 *           func_02027720, func_0202772C, func_02027738, func_02027740,
 *           func_02027748, func_0202774C, func_02027750, func_02027754,
 *           func_02027758, func_0202775C, func_02027760, func_02027764,
 *           func_02027768, func_0202776C, func_02027770, func_02027774
 * address:  0x02027710
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Offset accessors and constants in beacon_status.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02027710.c \
 *       --addr 0x02027710 --thumb --cc 1.1p1
 */

int func_02027710(int a)
{
    return a + 0x51;
}

int func_02027714(int a)
{
    return a + 0x54;
}

int func_02027718(int a)
{
    return a + 0xa6;
}

int func_0202771C(int a)
{
    return a + 0xa9;
}

int func_02027720(int a)
{
    if (a == 0) {
        a = 4;
    }
    return a + 0x56;
}

int func_0202772C(int a)
{
    if (a == 0) {
        a = 4;
    }
    return a + 0x6f;
}

int func_02027738(int dummy, int b)
{
    return b + 0x89;
}

int func_02027740(int dummy, int b)
{
    return b + 0x8c;
}

int func_02027748(void)
{
    return 0x8f;
}

int func_0202774C(int a)
{
    return a + 0x90;
}

int func_02027750(int a)
{
    return a + 0x93;
}

int func_02027754(int a)
{
    return a + 0x96;
}

int func_02027758(void)
{
    return 0;
}

int func_0202775C(int a)
{
    return a + 2;
}

int func_02027760(int a)
{
    return a + 5;
}

int func_02027764(int a)
{
    return a + 8;
}

int func_02027768(void)
{
    return 0x99;
}

int func_0202776C(int a)
{
    return a + 0x9a;
}

int func_02027770(int a)
{
    return a + 0x9d;
}

int func_02027774(int a)
{
    return a + 0xa0;
}
