/*
 * function: func_0273063C
 * address:  0x0273063C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732F60 0x02732F60 data twl
 *   data_02732F64 0x02732F64 data twl
 *   data_02732F68 0x02732F68 data twl
 *   data_02732F6C 0x02732F6C data twl
 *   func_02730868 0x02730868 arm twl
 *   func_027309FC 0x027309FC arm twl
 *   func_02730B48 0x02730B48 arm twl
 *   func_02730C2C 0x02730C2C arm twl
 *   func_02730CC0 0x02730CC0 arm twl
 *   func_02730D50 0x02730D50 arm twl
 *   func_02730DE4 0x02730DE4 arm twl
 *   func_02730EEC 0x02730EEC arm twl
 *   func_02731000 0x02731000 arm twl
 *   func_02731060 0x02731060 arm twl
 *   func_027310C0 0x027310C0 arm twl
 *   func_02731154 0x02731154 arm twl
 *   func_027311A0 0x027311A0 arm twl
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern int *data_02732F60;
extern u32 *data_02732F64;
extern int data_02732F68;
extern u16 data_02732F6C[3][8];
extern u32 func_02730868(u32 ch, int n, u32 val);
extern u32 func_027309FC(u32 ch, int start, int n, u32 val);
extern u32 func_02730B48(u32 ch, u32 val);
extern u32 func_02730C2C(u32 ch, int start, int n, u32 val);
extern u32 func_02730CC0(u32 ch, u32 val, u32 newval);
extern u32 func_02730D50(u32 ch, int start, int n, u32 val, u32 newval);
extern u32 func_02730DE4(u32 ch, int n, u32 val);
extern u32 func_02730EEC(u32 ch, int start, int n, u32 val);
extern u32 func_02731000(u32 ch, u32 val);
extern u32 func_02731060(u32 ch, int start, int n, u32 val);
extern u32 func_027310C0(u32 ch, u32 val);
extern void func_02731154(u32 a, u32 b);
extern void func_027311A0(u32 data, u32 *cmd, u32 *p2, u32 *p3, u32 *p4);

void func_0273063C(u32 tag, u32 data, int err)
{
    u32 cmd, arg, ch, sub;
    u32 result;

    if (err == 0) {
    result = 0;

    func_027311A0(data, &cmd, &ch, &sub, &arg);
    switch (cmd) {
    case 1:
        result = func_02730868(ch, (arg >> 8) & 0xFF, sub);
        break;
    case 2:
        result = func_027309FC(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 3:
        result = func_02730B48(ch, sub);
        break;
    case 4:
        result = func_02730C2C(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 5:
        result = func_02730CC0(ch, sub, (arg >> 12) & 3);
        break;
    case 6:
        result = func_02730D50(ch, (arg >> 8) & 0xF, arg & 0xFF, sub, (arg >> 12) & 3);
        break;
    case 7:
        result = func_02730DE4(ch, arg & 0xFF, sub);
        break;
    case 8:
        result = func_02730EEC(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 9:
        result = func_02731000(ch, sub);
        break;
    case 10:
        result = func_02731060(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 11:
        result = (data_02732F6C[ch][arg] & 0x300) >> 8;
        break;
    case 14:
        result = func_027310C0(ch, sub) & 0xFF;
        break;
    }
    func_02731154(1, result);
    } else {
        if (data_02732F64 != 0) {
            *data_02732F64 = data;
        }
        if (data_02732F60 != 0) {
            *data_02732F60 = 1;
        }
        data_02732F68 = 0;
    }
}
