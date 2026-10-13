/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200F7C0
 * packet:   pkt_0200F6D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_NET_ERR_HaltWithMessage, GFL_NET_ERR_Halt, GFL_NET_ERR_SetKeepDark, GFL_NET_ERR_ClearKeepDark
 *
 * symbols:
 *   GFL_NET_ERR_SetKeepDark  0x0200F7E8  thumb
 *   sub_0200F7B8       0x0200F7B8  thumb
 *   sub_0200F7C0_Obj   0x0214617C  data
 *   sub_0200F7C0_Flags 0x021461BC  data
 *
 * Four functions with no register-saving prologue, printed by disasm.py as
 * a run of .word between two labelled neighbours (sub_0200F7B8 before,
 * func_0200F800 after); see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md. Recovered by
 * hand-decoding the .word run and confirmed against the section map of
 * `match.py tu`.
 *
 * GFL_NET_ERR_HaltWithMessage and GFL_NET_ERR_Halt both tail-call sub_0200F7B8 (itself a
 * four-byte tail call to GFL_NET_ERR_ProcScreen, matched separately); neither
 * clears r0 first, so the argument each passes reaches GFL_NET_ERR_ProcScreen
 * unchanged. GFL_NET_ERR_SetKeepDark is a plain setter on the module-wide object at
 * 0x0214617C, and GFL_NET_ERR_ClearKeepDark tail-calls it with a fixed zero.
 *
 * sub_0200F7B8's only two callers in the whole ROM are GFL_NET_ERR_HaltWithMessage and
 * GFL_NET_ERR_Halt, both inside this same range; a third call site elsewhere
 * in the image gives match.py's label class a witness outside the range,
 * so the relocation resolves.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200F7C0.c \
 *       --addr 0x0200F7C0 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 sub_0200F7B8(u32 a0);

struct Sub0200F7C0Obj {
    u8 pad[0x64];
};

struct Sub0200F7C0Flags {
    u8 pad[0x1b];
};

extern struct Sub0200F7C0Obj sub_0200F7C0_Obj;
extern struct Sub0200F7C0Flags sub_0200F7C0_Flags;

void GFL_NET_ERR_HaltWithMessage(u32 value)
{
    *(u32 *)((u8 *)&sub_0200F7C0_Obj + 0x60) = value;
    *(u8 *)((u8 *)&sub_0200F7C0_Flags + 0x1a) = 1;
    *(u8 *)((u8 *)&sub_0200F7C0_Flags + 0x19) = 1;
    sub_0200F7B8(1);
}

void GFL_NET_ERR_Halt(void)
{
    sub_0200F7B8(1);
}

void GFL_NET_ERR_SetKeepDark(u32 value)
{
    *(u32 *)((u8 *)&sub_0200F7C0_Obj + 0x44) = value;
}

void GFL_NET_ERR_ClearKeepDark(void)
{
    GFL_NET_ERR_SetKeepDark(0);
}
