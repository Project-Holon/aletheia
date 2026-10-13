/*
 * function: MIi_CallbackForPxi
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
 *   MIi_DoAllocWram 0x02730868 arm twl
 *   MIi_DoAllocWramSlot 0x027309FC arm twl
 *   MIi_DoFreeWram 0x02730B48 arm twl
 *   MIi_DoFreeWramSlot 0x02730C2C arm twl
 *   MIi_DoSwitchWram 0x02730CC0 arm twl
 *   MIi_DoSwitchWramSlot 0x02730D50 arm twl
 *   MIi_DoReserveWram 0x02730DE4 arm twl
 *   MIi_DoReserveWramSlot 0x02730EEC arm twl
 *   MIi_DoCancelWram 0x02731000 arm twl
 *   MIi_DoCancelWramSlot 0x02731060 arm twl
 *   MIi_DoGetAllocatableWramSlot 0x027310C0 arm twl
 *   MIi_SendToPxi 0x02731154 arm twl
 *   MIi_TakeApartData 0x027311A0 arm twl
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern int *data_02732F60;
extern u32 *data_02732F64;
extern int data_02732F68;
extern u16 data_02732F6C[3][8];
extern u32 MIi_DoAllocWram(u32 ch, int n, u32 val);
extern u32 MIi_DoAllocWramSlot(u32 ch, int start, int n, u32 val);
extern u32 MIi_DoFreeWram(u32 ch, u32 val);
extern u32 MIi_DoFreeWramSlot(u32 ch, int start, int n, u32 val);
extern u32 MIi_DoSwitchWram(u32 ch, u32 val, u32 newval);
extern u32 MIi_DoSwitchWramSlot(u32 ch, int start, int n, u32 val, u32 newval);
extern u32 MIi_DoReserveWram(u32 ch, int n, u32 val);
extern u32 MIi_DoReserveWramSlot(u32 ch, int start, int n, u32 val);
extern u32 MIi_DoCancelWram(u32 ch, u32 val);
extern u32 MIi_DoCancelWramSlot(u32 ch, int start, int n, u32 val);
extern u32 MIi_DoGetAllocatableWramSlot(u32 ch, u32 val);
extern void MIi_SendToPxi(u32 a, u32 b);
extern void MIi_TakeApartData(u32 data, u32 *cmd, u32 *p2, u32 *p3, u32 *p4);

void MIi_CallbackForPxi(u32 tag, u32 data, int err)
{
    u32 cmd, arg, ch, sub;
    u32 result;

    if (err == 0) {
    result = 0;

    MIi_TakeApartData(data, &cmd, &ch, &sub, &arg);
    switch (cmd) {
    case 1:
        result = MIi_DoAllocWram(ch, (arg >> 8) & 0xFF, sub);
        break;
    case 2:
        result = MIi_DoAllocWramSlot(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 3:
        result = MIi_DoFreeWram(ch, sub);
        break;
    case 4:
        result = MIi_DoFreeWramSlot(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 5:
        result = MIi_DoSwitchWram(ch, sub, (arg >> 12) & 3);
        break;
    case 6:
        result = MIi_DoSwitchWramSlot(ch, (arg >> 8) & 0xF, arg & 0xFF, sub, (arg >> 12) & 3);
        break;
    case 7:
        result = MIi_DoReserveWram(ch, arg & 0xFF, sub);
        break;
    case 8:
        result = MIi_DoReserveWramSlot(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 9:
        result = MIi_DoCancelWram(ch, sub);
        break;
    case 10:
        result = MIi_DoCancelWramSlot(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 11:
        result = (data_02732F6C[ch][arg] & 0x300) >> 8;
        break;
    case 14:
        result = MIi_DoGetAllocatableWramSlot(ch, sub) & 0xFF;
        break;
    }
    MIi_SendToPxi(1, result);
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
