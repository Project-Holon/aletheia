#!/usr/bin/env python3
"""netptr.py: pointer types for the GFL network API and libc form for the MSL string functions
(lane P3NET, wave 20 phase 3).  Text edits only; every rule is idempotent; dry run by default.

Groups (all four are applied together; each group alone is listed for the tests):
  CMD      GFL_NET_COMMAND_Init / AddCommandTable / SetSendSlot take NetCommandEntry *, void *,
           GFLNetHandle *; GFLNetInitializeStruct.recvFuncTable is NetCommandEntry *; the callers
           lose their (u32) casts and declare the command tables as NetCommandEntry arrays.
  USERARG  GFL_NET_StartSession(req, GFLNetUserFunc callback, void *work); the session user
           argument, GFL_NET_Get/SetUserArg, the exit, init, connect, changeover and IRC wireless
           callbacks take void *; GFL_NET_Exit(GFLNetUserFunc).  The callbacks of the overlays
           (CALLBACKS) take a void * and cast it to their work type.
  SIZET    one size_t, unsigned long (types.h): the SDK C library says unsigned long (libc string.h,
           dwc_main strlen); the per-file typedef unsigned int size_t copies go.  Evidence: all MSL
           files stay EXACT with it.
  MSL      strlen, strncpy, strncmp, strchr, strstr, memcmp, strcmp_nocase take the libc form (const
           char *, size_t, void *); the u8 casts at their calls and the local externs go; qsort gets a
           prototype in msl_stdlib.h; the local atof/atoi/strtoul/qsort externs use the MSL headers.
           rand stays u32 (gpiconnect.c divides it as unsigned).
MSL needs SIZET (libc size_t is unsigned long); CMD and USERARG need each other's files only through
the shared headers, so apply everything.

  python tools/netptr.py                    dry run on the repo (lists files and blockers)
  python tools/netptr.py --claims CLAIMS.py --lane P3NET --apply
                                            claim and edit every file; refuses when a file is held
  python tools/netptr.py --root DIR         work on DIR/src/game (a scratch copy), no claims

After --apply run gameverify --file on the changed .c files and the includers of the changed headers,
hostcheck, protocheck, and gamelink for the overlays listed by the dry run.
"""
import argparse
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(HERE)

# ---------------------------------------------------------------------------
# Literal rules: group -> [(file under src/game, old, new)].  A rule whose old
# text is missing and whose new text is present counts as done.
# ---------------------------------------------------------------------------
LIT = {}
CALLS = {}      # group -> {"AddCommandTable": [files], ...} filled by scan()


def lit(group, path, pairs):
    LIT.setdefault(group, []).extend((path, a, b) for a, b in pairs)


# --- group CMD: command tables ---------------------------------------------
lit('CMD', 'arm9/net_command.c', [
    ("GFL_NET_COMMAND_Init(u32 groupKey, u32 commandList, u32 listNum, u32 userData, u32 unusedArg)",
     "GFL_NET_COMMAND_Init(u32 groupKey, NetCommandEntry *commandList, u32 listNum, void *userData, u32 unusedArg)"),
    ("GFL_NET_COMMAND_AddCommandTable(u32 groupKey, u32 commandList, u32 listNum, u32 userData)",
     "GFL_NET_COMMAND_AddCommandTable(u32 groupKey, NetCommandEntry *commandList, u32 listNum, void *userData)"),
    ("GFL_NET_COMMAND_SetSendSlot(u32 handle, u32 destMask, u32 command, u32 totalSize, u32 dataAddr)",
     "GFL_NET_COMMAND_SetSendSlot(GFLNetHandle *handle, u32 destMask, u32 command, u32 totalSize, void *dataAddr)"),
    ("(NetCommandEntry *)commandList", "commandList"),
    ("= (void *)userData;", "= userData;"),
    ("slot->dataAddr = (void *)dataAddr;", "slot->dataAddr = dataAddr;"),
    ("GFL_NET_HANDLE_GetNetHandleID((void *)handle)", "GFL_NET_HANDLE_GetNetHandleID(handle)"),
])
lit('CMD', 'arm9/net_command.h', [
    ("GFL_NET_COMMAND_Init(u32 groupKey, u32 commandList, u32 listNum, u32 userData, u32 unusedArg)",
     "GFL_NET_COMMAND_Init(u32 groupKey, NetCommandEntry *commandList, u32 listNum, void *userData, u32 unusedArg)"),
    ("GFL_NET_COMMAND_AddCommandTable(u32 groupKey, u32 commandList, u32 listNum, u32 userData)",
     "GFL_NET_COMMAND_AddCommandTable(u32 groupKey, NetCommandEntry *commandList, u32 listNum, void *userData)"),
    ("GFL_NET_COMMAND_SetSendSlot(u32 handle, u32 destMask, u32 command, u32 totalSize, u32 dataAddr)",
     "GFL_NET_COMMAND_SetSendSlot(GFLNetHandle *handle, u32 destMask, u32 command, u32 totalSize, void *dataAddr)"),
])
lit('CMD', 'arm9/net_types.h', [
    ("    u32   recvFuncTable;", "    struct NetCommandEntry *recvFuncTable;"),
])
lit('CMD', 'arm9/net.c', [
    ("void GFL_NET_COMMAND_Init(u32 gameKindShifted, u32 recvFuncTable, u32 recvFuncTableNum, u32 userArg, u32 heapId);",
     "void GFL_NET_COMMAND_Init(u32 gameKindShifted, NetCommandEntry *recvFuncTable, u32 recvFuncTableNum, void *userArg, u32 heapId);"),
])

# --- group USERARG: session start, user argument, callbacks ------------------
lit('USERARG', 'arm9/net_types.h', [
    ("struct GFLNetSession;\n",
     "struct GFLNetSession;\n\n/* Callback that gets the session's user argument (the caller's work pointer). */\n"
     "typedef void (*GFLNetUserFunc)(void *userArg);\n"),
    ("void (*connectFunc)(u32 netID, u32 userArg);", "void (*connectFunc)(void *userArg, u32 netID);"),
    ("u32  (*negotiationFunc)(u32 userArg);", "u32  (*negotiationFunc)(void *userArg);"),
    ("u32  (*negotiationSizeFunc)(u32 userArg);", "u32  (*negotiationSizeFunc)(void *userArg);"),
    ("void (*stateChangeFunc)(u32 handle, u32 state, u32 userArg);", "void (*stateChangeFunc)(u32 handle, u32 state, void *userArg);"),
    ("void (*errorStateFunc)(u32 handle, u32 state, u32 userArg);", "void (*errorStateFunc)(u32 handle, u32 state, void *userArg);"),
    ("void (*connectEndFunc)(u32 userArg);", "void (*connectEndFunc)(void *userArg);"),
    ("void (*deviceReadyFunc)(u32 userArg);", "void (*deviceReadyFunc)(void *userArg);"),
    ("void (*deleteFriendFunc)(u32 deletedIndex, u32 srcIndex, u32 userArg);", "void (*deleteFriendFunc)(u32 deletedIndex, u32 srcIndex, void *userArg);"),
    ("u32  (*getFriendListFunc)(u32 userArg);", "u32  (*getFriendListFunc)(void *userArg);"),
    ("u32  (*getWifiUserDataFunc)(u32 userArg);", "u32  (*getWifiUserDataFunc)(void *userArg);"),
    ("void (*exitCallback)(u32 userArg);", "GFLNetUserFunc exitCallback;"),
    ("\n    u32  userArg;\n", "\n    void *userArg;\n"),
    ("\n    u32    callbackArg;\n", "\n    void  *callbackArg;\n"),
    ("void (*savedConnectEndFunc)(u32 userArg);", "void (*savedConnectEndFunc)(void *userArg);"),
    ("    void (*onFinishedFunc)(u32 arg);\n    void (*onResultFunc)(u32 arg, int flag);\n    void (*onReadyFunc)(u32 arg);",
     "    GFLNetUserFunc onFinishedFunc;\n    void (*onResultFunc)(void *arg, int flag);\n    GFLNetUserFunc onReadyFunc;"),
    ("u32 wmParam, u32 userData);", "u32 wmParam, void *userData);"),
])
lit('USERARG', 'arm9/net.h', [
    ("void GFL_NET_StartSession(GFLNetInitializeStruct *req, u32 transportArg, u32 userArg);",
     "void GFL_NET_StartSession(GFLNetInitializeStruct *req, GFLNetUserFunc callback, void *work);"),
    ("int GFL_NET_Exit(void (*exitCallback)(u32));", "int GFL_NET_Exit(GFLNetUserFunc exitCallback);"),
    ("u32 GFL_NET_GetUserArg(void);", "void *GFL_NET_GetUserArg(void);"),
    ("void GFL_NET_SetUserArg(u32 userArg);", "void GFL_NET_SetUserArg(void *userArg);"),
    ("void GFL_NET_StartChangeoverEx(u32 onFinished, u32 onResult, u32 onReady);",
     "void GFL_NET_StartChangeoverEx(GFLNetUserFunc onFinished, void (*onResult)(void *, int), GFLNetUserFunc onReady);"),
    ("void GFL_NET_StartChangeoverChild(u32 changeoverParam);", "void GFL_NET_StartChangeoverChild(GFLNetUserFunc changeoverParam);"),
    ("void GFL_NET_StartChangeoverParent(u32 changeoverParam);", "void GFL_NET_StartChangeoverParent(GFLNetUserFunc changeoverParam);"),
])
lit('USERARG', 'arm9/net.c', [
    ("void GFL_NET_STATE_DeviceInitialize(void *heapId, u32 initCallback);",
     "void GFL_NET_STATE_DeviceInitialize(void *heapId, GFLNetUserFunc initCallback);"),
    ("void GFL_NET_StartSession(GFLNetInitializeStruct *req, u32 transportArg, u32 userArg)",
     "void GFL_NET_StartSession(GFLNetInitializeStruct *req, GFLNetUserFunc callback, void *work)"),
    ("int GFL_NET_Exit(void (*exitCallback)(u32))", "int GFL_NET_Exit(GFLNetUserFunc exitCallback)"),
    ("u32 GFL_NET_GetUserArg(void)", "void *GFL_NET_GetUserArg(void)"),
    ("void GFL_NET_SetUserArg(u32 userArg)", "void GFL_NET_SetUserArg(void *userArg)"),
    ("GFL_NET_IRC_WIRELESS_Create(const GFLNetInitializeStruct *src, u32 callbackArg);",
     "GFL_NET_IRC_WIRELESS_Create(const GFLNetInitializeStruct *src, void *callbackArg);"),
    ("GFL_NET_IRC_WIRELESS_Create((const GFLNetInitializeStruct *)req, userArg);",
     "GFL_NET_IRC_WIRELESS_Create((const GFLNetInitializeStruct *)req, work);"),
    ("    session->userArg = userArg;\n    GFL_NET_STATE_DeviceInitialize((void *)req->heapId, transportArg);",
     "    session->userArg = work;\n    GFL_NET_STATE_DeviceInitialize((void *)req->heapId, callback);"),
    ("    void (*callback)(u32);\n    u16 heapId;", "    GFLNetUserFunc callback;\n    u16 heapId;"),
    ("void GFL_NET_STATE_StartChangeover(u16 heapId, u32 changeoverParam, u8 mode);",
     "void GFL_NET_STATE_StartChangeover(u16 heapId, GFLNetUserFunc changeoverParam, u8 mode);"),
    ("void GFL_NET_StartChangeoverChild(u32 changeoverParam)", "void GFL_NET_StartChangeoverChild(GFLNetUserFunc changeoverParam)"),
    ("void GFL_NET_StartChangeoverParent(u32 changeoverParam)", "void GFL_NET_StartChangeoverParent(GFLNetUserFunc changeoverParam)"),
    ("void GFL_NET_StartChangeoverEx(u32 onFinished, u32 onResult, u32 onReady)",
     "void GFL_NET_StartChangeoverEx(GFLNetUserFunc onFinished, void (*onResult)(void *, int), GFLNetUserFunc onReady)"),
    ("    u32 handler = onFinished;\n", "    GFLNetUserFunc handler = onFinished;\n"),
    ("handler = (u32)GFL_NET_IRC_WIRELESS_SetCallbacks((void (*)(u32))onFinished, (void (*)(u32, int))onResult, (void (*)(u32))onReady);",
     "handler = GFL_NET_IRC_WIRELESS_SetCallbacks(onFinished, onResult, onReady);"),
    ("void *GFL_NET_IRC_WIRELESS_SetCallbacks(void (*onFinished)(u32), void (*onResult)(u32, int), void (*onReady)(u32));",
     "GFLNetUserFunc GFL_NET_IRC_WIRELESS_SetCallbacks(GFLNetUserFunc onFinished, void (*onResult)(void *, int), GFLNetUserFunc onReady);"),
])
lit('USERARG', 'arm9/net_state.c', [
    ("    void (*initCallback)(u32 a);", "    GFLNetUserFunc initCallback;"),
    ("void GFL_NET_STATE_DeviceInitialize(void *heapId, u32 initCallback)", "void GFL_NET_STATE_DeviceInitialize(void *heapId, GFLNetUserFunc initCallback)"),
    ("_pNetState->initCallback = (void (*)(u32))initCallback;", "_pNetState->initCallback = initCallback;"),
    ("void GFL_NET_STATE_StartChangeover(u16 unusedArg, u32 initCallback, u8 hasMac)",
     "void GFL_NET_STATE_StartChangeover(u16 unusedArg, GFLNetUserFunc initCallback, u8 hasMac)"),
])
lit('USERARG', 'arm9/net_state.h', [
    ("void GFL_NET_STATE_DeviceInitialize(void *heapId, u32 initCallback);", "void GFL_NET_STATE_DeviceInitialize(void *heapId, GFLNetUserFunc initCallback);"),
    ("void GFL_NET_STATE_StartChangeover(u16 unusedArg, u32 initCallback, u8 hasMac);", "void GFL_NET_STATE_StartChangeover(u16 unusedArg, GFLNetUserFunc initCallback, u8 hasMac);"),
])
lit('USERARG', 'arm9/net_irc_wireless.c', [
    ("GFL_NET_IRC_WIRELESS_Create(const GFLNetInitializeStruct *src, u32 callbackArg)", "GFL_NET_IRC_WIRELESS_Create(const GFLNetInitializeStruct *src, void *callbackArg)"),
    ("void GFL_NET_IRC_WIRELESS_OnConnectEnd(u32 userArg)", "void GFL_NET_IRC_WIRELESS_OnConnectEnd(void *userArg)"),
    ("void GFL_NET_IRC_WIRELESS_OnSyncReady(void)", "void GFL_NET_IRC_WIRELESS_OnSyncReady(void *userArg)"),
    ("void *GFL_NET_IRC_WIRELESS_SetCallbacks(void (*onFinished)(u32), void (*onResult)(u32, int), void (*onReady)(u32))",
     "GFLNetUserFunc GFL_NET_IRC_WIRELESS_SetCallbacks(GFLNetUserFunc onFinished, void (*onResult)(void *, int), GFLNetUserFunc onReady)"),
    ("GFL_NET_StartChangeoverChild((u32)GFL_NET_IRC_WIRELESS_OnSyncReady);", "GFL_NET_StartChangeoverChild(GFL_NET_IRC_WIRELESS_OnSyncReady);"),
])
lit('USERARG', 'arm9/net_irc_wireless.h', [
    ("GFL_NET_IRC_WIRELESS_Create(const GFLNetInitializeStruct *src, u32 callbackArg)", "GFL_NET_IRC_WIRELESS_Create(const GFLNetInitializeStruct *src, void *callbackArg)"),
    ("void GFL_NET_IRC_WIRELESS_OnConnectEnd(u32 userArg);", "void GFL_NET_IRC_WIRELESS_OnConnectEnd(void *userArg);"),
    ("void GFL_NET_IRC_WIRELESS_OnSyncReady(void);", "void GFL_NET_IRC_WIRELESS_OnSyncReady(void *userArg);"),
    ("void *GFL_NET_IRC_WIRELESS_SetCallbacks(void (*onFinished)(u32), void (*onResult)(u32, int), void (*onReady)(u32));",
     "GFLNetUserFunc GFL_NET_IRC_WIRELESS_SetCallbacks(GFLNetUserFunc onFinished, void (*onResult)(void *, int), GFLNetUserFunc onReady);"),
])
lit('USERARG', 'arm9/net_system.c', [
    ("void (*hook)(u32, u32);", "void (*hook)(void *, u32);"),
])

# --- group USERARG: overlay literals ----------------------------------------
lit('USERARG', 'ov009/dwc_rap.c', [
    ("u32 GFL_NET_GetUserArg(void);\n", ""),
    ("u32 userArg = GFL_NET_GetUserArg();", "void *userArg = GFL_NET_GetUserArg();"),
])
lit('USERARG', 'ov009/dwc_rap_types.h', [
    ("int (*acceptFriendFunc)(int, u32);", "int (*acceptFriendFunc)(int, void *);"),
])
lit('USERARG', 'ov014/wih.c', [
    ("typedef int (*WihJudgeAcceptFunc)(void *startParentCb, u32 now);",
     "typedef int (*WihJudgeAcceptFunc)(void *startParentCb, void *userArg);"),
    ("typedef void (*WihBeaconFoundCallback)(void *bssDesc, u32 now, u16 linkLevel);",
     "typedef void (*WihBeaconFoundCallback)(void *bssDesc, void *userArg, u16 linkLevel);"),
])
lit('USERARG', 'ov021/comm_entry_menu.c', [
    ("    u32 savedUserArg; ", "    void *savedUserArg;"),
])
lit('USERARG', 'ov010/game_beacon_search.c', [
    ("extern void GFL_NET_StartSession(struct GFLNetInitializeStruct *req, u32 transportArg, u32 userArg);\n", ""),
    ("extern int GFL_NET_Exit(void (*callback)(void *work));\n", "#include \"../arm9/net.h\"\n"),
])
lit('USERARG', 'ov011/intrude_comm.c', [
    ("extern void GFL_NET_StartSession(GFLNetInitializeStruct *init, u32 callback, u32 userArg);",
     "extern void GFL_NET_StartSession(GFLNetInitializeStruct *init, GFLNetUserFunc callback, void *work);"),
    ("extern void GFL_NET_StartChangeoverParent(u32 changeoverParam);",
     "extern void GFL_NET_StartChangeoverParent(GFLNetUserFunc changeoverParam);"),
    ("extern int GFL_NET_Exit(void (*exitCallback)(IntrudeCommSys *work));",
     "extern int GFL_NET_Exit(GFLNetUserFunc exitCallback);"),
])
lit('USERARG', 'ov009/dwc_rap.c', [
    ("(int (*)(int, u32))acceptFunc", "(int (*)(int, void *))acceptFunc"),
])
lit('USERARG', 'ov101/compatible_irc_sys.h', [
    ('#include "../types.h"\n',
     '#include "../types.h"\n#include "../arm9/net_types.h"\n'),
])
lit('USERARG', 'ov010/script_sys.c', [
    ("extern int GFL_NET_Exit(void (*exitCallback)(u32));\n",
     "extern int GFL_NET_Exit(void (*exitCallback)(void *userArg));\n"),
    ("int GFL_NET_IsSessionNull();\n",
     "#ifdef __MWERKS__\n"
     "int GFL_NET_IsSessionNull();    /* the original has no parameter list and is called with the Main result */\n"
     "#else\nint GFL_NET_IsSessionNull(void);\n#endif\n"),
    ("        while (GFL_NET_IsSessionNull(GFL_NET_Main()) == 0)\n",
     "#ifdef __MWERKS__\n        while (GFL_NET_IsSessionNull(GFL_NET_Main()) == 0)\n#else\n"
     "        while ((GFL_NET_Main(), GFL_NET_IsSessionNull()) == 0)\n#endif\n"),
])
lit('USERARG', 'ov099/wifi_club_actor.c', [
    ("u8 *WIFICLUBACTOR_GetCommandTable(void)", "NetCommandEntry *WIFICLUBACTOR_GetCommandTable(void)"),
    ("    return data_021C28A8;", "    return (NetCommandEntry *)data_021C28A8;"),
])
lit('USERARG', 'ov099/wifi_club_actor.h', [
    ("u8 *WIFICLUBACTOR_GetCommandTable(void);", "NetCommandEntry *WIFICLUBACTOR_GetCommandTable(void);"),
    ('#include "../types.h"\n', '#include "../types.h"\n#include "../arm9/net_types.h"\n'),
])
lit('USERARG', 'ov010/bsubway_comm.c', [
    ("void BSUBWAY_COMM_AddCommandTable(u32 work)", "void BSUBWAY_COMM_AddCommandTable(void *work)")])
lit('USERARG', 'ov010/bsubway_comm.h', [
    ("void BSUBWAY_COMM_AddCommandTable(u32 work);", "void BSUBWAY_COMM_AddCommandTable(void *work);")])
lit('USERARG', 'ov137/guru2_comm.c', [
    ("void GURU2_COMM_RegisterCommands(u32 a);", "void GURU2_COMM_RegisterCommands(void *work);"),
    ("void GURU2_COMM_RegisterCommands(u32 work)", "void GURU2_COMM_RegisterCommands(void *work)"),
])
lit('USERARG', 'ov137/guru2_comm.h', [
    ("void GURU2_COMM_RegisterCommands(u32 work);", "void GURU2_COMM_RegisterCommands(void *work);")])
lit('USERARG', 'ov101/compatible_irc_sys.c', [
    ("void COMPATIBLE_IRC_SYS_AddCommandTable(IrcSys *sys,u32 a,u32 b,u32 c,u32 d)",
     "void COMPATIBLE_IRC_SYS_AddCommandTable(IrcSys *sys,u32 a,NetCommandEntry *b,u32 c,void *d)"),
])
lit('USERARG', 'ov101/compatible_irc_sys.h', [
    ("void COMPATIBLE_IRC_SYS_AddCommandTable(IrcSys *sys,u32 a,u32 b,u32 c,u32 d);",
     "void COMPATIBLE_IRC_SYS_AddCommandTable(IrcSys *sys,u32 a,NetCommandEntry *b,u32 c,void *d);"),
])
lit('USERARG', 'ov115/wifilogin_message.c', [
    ("GFL_NET_Exit((void (*)(u32))((int)WIFILOGIN_MSG_SetExitFlag))", "GFL_NET_Exit(WIFILOGIN_MSG_SetExitFlag)"),
])
lit('USERARG', 'ov121/mystery_net.c', [
    ("#define GFL_NET_StartSession GFL_NET_StartSession_hdr\n", ""),
    ("#define GFL_NET_Exit GFL_NET_Exit_hdr\n", ""),
    ("#undef GFL_NET_StartSession\n", ""),
    ("#undef GFL_NET_Exit\n", ""),
    ("void GFL_NET_StartSession(GFLNetInitializeStruct *, unsigned int, unsigned int);\n", ""),
    ("int GFL_NET_Exit(void (*exitCallback)(u32));\n", ""),
    ("((int (*)(int))GFL_NET_Exit)(0)", "GFL_NET_Exit(0)"),
])
lit('USERARG', 'ov115/wifilogin_disp.c', [
    ("GFL_NET_StartSession((GFLNetInitializeStruct *)d_021D6560,z,(u32)p);",
     "GFL_NET_StartSession((GFLNetInitializeStruct *)d_021D6560,0,p);"),
])

lit('MSL', 'arm9/msl_printf.c', [
    ("    const uchar *curr_format;", "    const char *curr_format;"),
    ("curr_format = strchr(format_ptr, '%')", "curr_format = strchr((const char *)format_ptr, '%')"),
    ("num_chars = strlen(format_ptr);", "num_chars = strlen((const char *)format_ptr);"),
    ("num_chars = strlen(buff_ptr);", "num_chars = strlen((const char *)buff_ptr);"),
    ("num_chars = curr_format - format_ptr;", "num_chars = (const uchar *)curr_format - format_ptr;"),
    ("format_ptr = curr_format;", "format_ptr = (const uchar *)curr_format;"),
    ("(*WriteProc)(WriteProcArg, curr_format, num_chars)", "(*WriteProc)(WriteProcArg, (const uchar *)curr_format, num_chars)"),
])

lit('MSL', 'arm9/msl_stdio.c', [
    ("strncpy(dst + n, (const u8 *)&tmp, k);", "strncpy((char *)(dst + n), (const char *)&tmp, k);"),
    ("int __load_buffer(struct MslStream *stream, u32 *bytes_loaded, int mode)", "int __load_buffer(struct MslStream *stream, size_t *bytes_loaded, int mode)"),
])
lit('SIZET', 'types.h', [
    ("typedef unsigned long long u64;\n", "typedef unsigned long long u64;\n\n/* C library size type: unsigned long in the SDK C library (libc string.h, MSL). */\ntypedef unsigned long      size_t;\n"),
])

lit('MSL2', 'arm9/dwc_ac.c', [
    ("strncmp(ssid1, wk->bssDesc[i].bssid, wk->bssDesc[i].ssidLength)", "strncmp((const char *)ssid1, (const char *)wk->bssDesc[i].bssid, wk->bssDesc[i].ssidLength)"),
])
lit('MSL2', 'arm9/dwc_ac_connect.c', [
    ("strncmp(bssdesc->ssid, wk->searchList[i].ssid, bssdesc->ssidLength)", "strncmp((const char *)bssdesc->ssid, (const char *)wk->searchList[i].ssid, bssdesc->ssidLength)"),
])
lit('MSL2', 'arm9/dwc_ac_makelist.c', [
    ("strncmp(bssdesc->ssid, FREESPOT_SSID, 8)", "strncmp((const char *)bssdesc->ssid, (const char *)FREESPOT_SSID, 8)"),
])
lit('MSL2', 'ov009/dwc_http.c', [
    ("CPS_SocWrite(s, strlen(s))", "CPS_SocWrite(s, strlen((const char *)s))"),
])
lit('MSL2', 'ov009/dwc_transport.c', [
    ("strncpy(sendBuf, gDwcTransForwardMagic, 3);", "strncpy((char *)sendBuf, gDwcTransForwardMagic, 3);"),
])
lit('MSL2', 'ov009/gpipeer.c', [
    ("str = (char *)(unsigned char *)strstr(((const unsigned char *)peer->inputBuffer.buffer), ((const unsigned char *)gGpiPeerKeyFinal));",
     "str = (char *)strstr(peer->inputBuffer.buffer, gGpiPeerKeyFinal);"),
])
lit('MSL2', 'ov009/gt2buffer.c', [
    ("len = strlen(data);", "len = strlen((const char *)data);"),
])
lit('MSL2', 'ov009/gt2utility.c', [
    ("*len = strlen(*message) + 1;", "*len = strlen((const char *)*message) + 1;"),
])
lit('MSL2', 'ov016/common.c', [
    ("strncpy(gCommonWork, name, 0x3f);", "strncpy((char *)gCommonWork, (const char *)name, 0x3f);"),
])
lit('MSL', 'arm9/msl_stdlib.h', [
    ("u32 rand(void);", "u32 rand(void);\nvoid qsort(void *table_base, size_t num_members, size_t member_size, int (*compare_members)(const void *, const void *));"),
])

# Callbacks that get the session user argument: (file, function, work type).
CALLBACKS = [
    ('ov010/delivery_beacon.c', 'DELIVERY_BEACON_OnSessionStarted', 'DeliveryBeacon'),
    ('ov011/intrude_comm.c', 'INTRUDE_COMM_OnSessionStarted', 'IntrudeCommSys'),
    ('ov011/intrude_comm.c', 'INTRUDE_COMM_OnSessionExit', 'IntrudeCommSys'),
    ('ov012/union_comm.c', 'UNION_COMM_SessionStartCallback', 'UnionRoomWork'),
    ('ov012/union_comm.c', 'UNION_COMM_ExitCallback', 'UnionRoomWork'),
    ('ov101/compatible_irc_sys.c', 'COMPATIBLE_IRC_SYS_ExitCallback', 'IrcSys'),
    ('ov101/compatible_irc_sys.c', 'COMPATIBLE_IRC_SYS_StartSessionCallback', None),
    ('ov132/mus_comm_func.c', 'MUS_COMM_FUNC_SetReady', 'char'),
    ('ov115/wifilogin_message.c', 'WIFILOGIN_MSG_SetExitFlag', 'u8'),
    ('ov121/mystery_net.c', 'MYSTERY_NET_FlagExit', 'char'),
    ('ov100/ircbattlematch.c', 'IRCBATTLEMATCH_CollectMacAddresses', 'IrcBattleMatchWork'),
    ('ov100/ircbattlematch.c', 'IRCBATTLEMATCH_OnChangeoverConnected', 'IrcBattleMatchWork'),
    ('ov100/ircbattlematch.c', 'IRCBATTLEMATCH_OnChangeoverResult', 'IrcBattleMatchWork'),
]


def convert_callback(s, func, ty):
    """FUNC(Type *work[, rest]) -> FUNC(void *userArg[, rest]) with a typed local at the body top."""
    if ty is None:
        return re.sub(r'\b' + func + r'\(\s*void\s*\)', func + '(void *userArg)', s)
    sig = r'\b' + func + r'\(\s*' + re.escape(ty) + r'\s*\*\s*(\w+)\s*(,[^)]*)?\)'
    s = re.sub(sig + r'(\s*;)',
               lambda m: func + '(void *userArg' + (m.group(2) or '') + ')' + m.group(3), s)

    def definition(m):
        name, rest, ws, tail = m.group(1), m.group(2) or '', m.group(3), m.group(4)
        head = func + '(void *userArg' + rest + ')' + ws
        if '\n' in ws:
            return head + '{\n    ' + ty + ' *' + name + ' = userArg;\n' + tail
        return head + '{ ' + ty + ' *' + name + ' = userArg; ' + tail.lstrip(' ')
    return re.sub(sig + r'(\s*)\{([^\n]*\n)', lambda m: definition(m), s)


# --- group MSL: libc forms of the string functions -----------------------------
# rand stays u32: gpiconnect.c divides its result as unsigned (umull), so the
# original declaration returns an unsigned value; the three ov009 callers that
# declare int rand(void) keep that declaration (protocheck exceptions).
lit('MSL', 'arm9/msl_string_str.c', [
    ("int strlen(const u8 *s);", "size_t strlen(const char *str);"),
    ("u8 *strncpy(u8 *dest, const u8 *src, u32 n);", "char *strncpy(char *destStr, const char *srcStr, size_t n);"),
    ("int strncmp(const u8 *s1, const u8 *s2, u32 n);", "int strncmp(const char *str1, const char *str2, size_t n);"),
    ("u8 *strchr(const u8 *s, int c);", "char *strchr(const char *str, int c);"),
    ("u8 *strstr(const u8 *s1, const u8 *s2);", "char *strstr(const char *str1, const char *str2);"),
    ("int strlen(const u8 *s)\n{\n    int n = -1;\n", "size_t strlen(const char *str)\n{\n    const u8 *s = (const u8 *)str;\n    int n = -1;\n"),
    ("u8 *strncpy(u8 *dest, const u8 *src, u32 n)\n{\n    u8 *d = dest;\n\n    if (n == 0) {\n        return dest;\n    }\n",
     "char *strncpy(char *destStr, const char *srcStr, size_t n)\n{\n    u8 *dest = (u8 *)destStr;\n    const u8 *src = (const u8 *)srcStr;\n    u8 *d = dest;\n\n    if (n == 0) {\n        return destStr;\n    }\n"),
    ("            if (--n == 0) {\n                return dest;\n            }\n            do {\n                *d++ = 0;\n            } while (--n != 0);\n            return dest;\n        }\n\n        if (--n == 0) {\n            return dest;\n        }\n",
     "            if (--n == 0) {\n                return destStr;\n            }\n            do {\n                *d++ = 0;\n            } while (--n != 0);\n            return destStr;\n        }\n\n        if (--n == 0) {\n            return destStr;\n        }\n"),
    ("int strncmp(const u8 *s1, const u8 *s2, u32 n)\n{\n", "int strncmp(const char *str1, const char *str2, size_t n)\n{\n    const u8 *s1 = (const u8 *)str1;\n    const u8 *s2 = (const u8 *)str2;\n"),
    ("u8 *strchr(const u8 *s, int c)\n{\n    u8 m = (u8)c;\n", "char *strchr(const char *str, int c)\n{\n    const u8 *s = (const u8 *)str;\n    u8 m = (u8)c;\n"),
    ("            return (u8 *)s - 1;\n        ch = *s++;\n    }\n    return m ? 0 : (u8 *)s - 1;",
     "            return (char *)s - 1;\n        ch = *s++;\n    }\n    return m ? 0 : (char *)s - 1;"),
    ("u8 *strstr(const u8 *s1, const u8 *s2)\n{\n    u8 c2;", "char *strstr(const char *str1, const char *str2)\n{\n    const u8 *s1 = (const u8 *)str1;\n    const u8 *s2 = (const u8 *)str2;\n    u8 c2;"),
    ("        return (u8 *)s1;\n    }\n\n    c1 = *s1;", "        return (char *)s1;\n    }\n\n    c1 = *s1;"),
    ("                    return (u8 *)p - 1;", "                    return (char *)p - 1;"),
])
lit('MSL', 'arm9/msl_string_str.h', [
    ("int strlen(const u8 *s);", "size_t strlen(const char *str);"),
    ("u8 *strncpy(u8 *dest, const u8 *src, u32 n);", "char *strncpy(char *destStr, const char *srcStr, size_t n);"),
    ("int strncmp(const u8 *s1, const u8 *s2, u32 n);", "int strncmp(const char *str1, const char *str2, size_t n);"),
    ("u8 *strchr(const u8 *s, int c);", "char *strchr(const char *str, int c);"),
    ("u8 *strstr(const u8 *s1, const u8 *s2);", "char *strstr(const char *str1, const char *str2);"),
])
lit('MSL', 'arm9/msl_string_mem.c', [
    ("int memcmp(const u8 *s1, const u8 *s2, u32 n);", "int memcmp(const void *buf1, const void *buf2, size_t n);"),
    ("int memcmp(const u8 *s1, const u8 *s2, u32 n)\n{\n", "int memcmp(const void *buf1, const void *buf2, size_t n)\n{\n    const u8 *s1 = (const u8 *)buf1;\n    const u8 *s2 = (const u8 *)buf2;\n"),
])
lit('MSL', 'arm9/msl_string_mem.h', [
    ("int memcmp(const u8 *s1, const u8 *s2, u32 n);", "int memcmp(const void *buf1, const void *buf2, size_t n);"),
])
lit('MSL', 'arm9/msl_fdlibm.c', [
    ("int strcmp_nocase(const u8 *s1, const u8 *s2);", "int strcmp_nocase(const char *s1, const char *s2);"),
    ("int strcmp_nocase(const u8 *s1, const u8 *s2)\n{\n    return stricmp(s1, s2);", "int strcmp_nocase(const char *s1, const char *s2)\n{\n    return stricmp((const u8 *)s1, (const u8 *)s2);"),
])
lit('MSL', 'arm9/msl_fdlibm.h', [
    ("int strcmp_nocase(const u8 *s1, const u8 *s2);", "int strcmp_nocase(const char *s1, const char *s2);"),
])

# ---------------------------------------------------------------------------
# Call rewrites.
# ---------------------------------------------------------------------------
CASTRE = re.compile(r'^(\s*)\(\s*(?:u32|unsigned int|unsigned|int|u8 \*|char \*|void \*)\s*\)\s*')
INTCAST = re.compile(r'^(\s*)\(\s*(?:u32|unsigned int|unsigned|int)\s*\)\s*')
# call name -> argument indexes whose integer cast is removed
CALLARGS = {
    'GFL_NET_COMMAND_AddCommandTable': (1, 3),
    'GFL_NET_COMMAND_Init': (1, 3),
    'GFL_NET_COMMAND_SetSendSlot': (0, 4),
    'GFL_NET_StartSession': (1, 2),
    'GFL_NET_StartChangeoverEx': (0, 1, 2),
    'GFL_NET_SetUserArg': (0,),
    'COMPATIBLE_IRC_SYS_AddCommandTable': (2, 4),
    'BSUBWAY_COMM_AddCommandTable': (0,),
    'GURU2_COMM_RegisterCommands': (0,),
}
CALLRE = re.compile(r'\b(' + '|'.join(CALLARGS) + r')\(')
TABLE_ARG = {'GFL_NET_COMMAND_AddCommandTable': 1, 'GFL_NET_COMMAND_Init': 1, 'COMPATIBLE_IRC_SYS_AddCommandTable': 2}


def split_args(s, i):
    d = 0
    a = []
    st = i
    j = i
    n = len(s)
    while j < n:
        ch = s[j]
        if ch in '"\'':
            # skip a string or character literal
            k = j + 1
            while k < n and s[k] != ch:
                k += 2 if s[k] == '\\' else 1
            j = k + 1
            continue
        if s.startswith('/*', j):
            k = s.find('*/', j + 2)
            j = n if k < 0 else k + 2
            continue
        if ch in '([{':
            d += 1
        elif ch in ')]}':
            if d == 0:
                a.append(s[st:j])
                return a, j
            d -= 1
        elif ch == ',' and d == 0:
            a.append(s[st:j])
            st = j + 1
        j += 1
    return None, j


def rewrite_calls(s, tables):
    """Strip the integer casts at the listed call arguments; collect table names."""
    out = []
    pos = 0
    for m in CALLRE.finditer(s):
        if m.start() < pos:
            continue
        # skip declarations and definitions: a type name precedes the call name
        pre = s[max(0, m.start() - 12):m.start()]
        if re.search(r'(void|int|u32)\s+$', pre):
            continue
        args, end = split_args(s, m.end())
        if args is None:
            continue
        name = m.group(1)
        idx = CALLARGS[name]
        changed = False
        for k in idx:
            if k < len(args):
                n = INTCAST.sub(lambda mm: mm.group(1), args[k], count=1)
                if n != args[k]:
                    args[k] = n
                    changed = True
        if name in TABLE_ARG and TABLE_ARG[name] < len(args):
            t = args[TABLE_ARG[name]].strip()
            if re.fullmatch(r'[A-Za-z_]\w*', t):
                tables.add(t)
        if changed:
            out.append(s[pos:m.end()])
            out.append(','.join(args))
            pos = end
    out.append(s[pos:])
    return ''.join(out)


def retype_tables(s, tables):
    """extern <type> NAME[] -> extern NetCommandEntry NAME[] for the command tables."""
    for t in sorted(tables):
        # a single declaration
        pat = re.compile(r'^(\s*)extern\s+(?:const\s+)?(?:unsigned\s+int|unsigned|u32|u16|u8|char|int)\s+' + re.escape(t) + r'\s*\[\s*\]\s*;',
                         re.M)
        s = pat.sub(lambda mm: mm.group(1) + 'extern NetCommandEntry ' + t + '[];', s)
        # a name inside a comma list: split it out
        pat2 = re.compile(r'^(\s*extern\s+(?:const\s+)?(?:u32|u16|u8|char|int)\s+)([^;\n]*?)\b' + re.escape(t) + r'\[\]\s*,?\s*([^;\n]*);', re.M)
        def split(mm):
            head, before, after = mm.group(1), mm.group(2), mm.group(3)
            rest = (before + after).strip().strip(',')
            parts = [p for p in re.split(r'\s*,\s*', rest) if p]
            keep = (head + ','.join(parts) + ';') if parts else ''
            return (keep + '\n' if keep else '') + 'extern NetCommandEntry ' + t + '[];'
        s = pat2.sub(split, s)
    return s


LIBC_LOCAL = re.compile(r'^extern\s+[\w\s\*]*?\b(strncmp|strncpy|strchr|strstr|memcmp)\s*\(([^)]*)\)\s*;[ \t]*$', re.M)


def libc_locals(s):
    """Local extern prototypes of the MSL string functions take the libc form."""
    def one(m):
        name, params = m.group(1), m.group(2)
        ps = [x.strip() for x in params.split(',')]
        cnt = ''
        if len(ps) == 3:
            mm = re.match(r'(.*?)\s*\b\w+$', ps[2])
            cnt = mm.group(1) if mm and mm.group(1) else ps[2]
        forms = {
            'strncmp': 'extern int strncmp(const char *s1, const char *s2, %s n);' % cnt,
            'strncpy': 'extern char *strncpy(char *dest, const char *src, %s n);' % cnt,
            'strchr': 'extern char *strchr(const char *s, int c);',
            'strstr': 'extern char *strstr(const char *s1, const char *s2);',
            'memcmp': 'extern int memcmp(const void *a, const void *b, %s n);' % cnt,
        }
        return forms[name]
    return LIBC_LOCAL.sub(one, s)


LIBCFN = re.compile(r'\b(strncmp|strncpy|strchr|strstr|strlen|strcmp_nocase)\(')
PTRCAST = re.compile(r'^(\s*)\(\s*(?:const\s+)?(?:unsigned char|u8)\s*\*\s*\)\s*')
SIZET_TYPEDEF = re.compile(r'^typedef unsigned int +size_t;[ \t]*\r?\n', re.M)


def strip_libc_casts(s):
    """Arguments of the C library string calls lose their u8 pointer casts."""
    out = []
    pos = 0
    for m in LIBCFN.finditer(s):
        if m.start() < pos:
            continue
        pre = s[max(0, m.start() - 12):m.start()]
        if re.search(r'(void|int|char|u8|long) *[*]* *$', pre):
            continue
        args, end = split_args(s, m.end())
        if args is None:
            continue
        changed = False
        for k in range(len(args)):
            n = strip_libc_casts(PTRCAST.sub(lambda mm: mm.group(1), args[k], count=1))
            if n != args[k]:
                args[k] = n
                changed = True
        if changed:
            out.append(s[pos:m.end()])
            out.append(','.join(args))
            pos = end
    out.append(s[pos:])
    return ''.join(out)



LIBCEXT = re.compile(r'^extern[ \t]+[\w \t\*]*?\b(atof|atoi|strtoul|qsort)[ \t]*\([^)]*\)[ \t]*;[ \t]*$', re.M)
LIBCINC = {'atof': '../arm9/msl_strtod.h', 'atoi': '../arm9/msl_strtod.h', 'strtoul': '../arm9/msl_strtod.h',
           'qsort': '../arm9/msl_stdlib.h'}


def libc_externs(s):
    """Local externs of atof/atoi/strtoul/qsort go; the MSL header supplies them."""
    need = []

    def one(m):
        inc = LIBCINC[m.group(1)]
        if inc not in need:
            need.append(inc)
        return '\\MARK'
    t = LIBCEXT.sub(one, s)
    if t == s:
        return s
    for inc in need:
        line = '#include "%s"' % inc
        if line in t:
            t = t.replace('\\MARK\n', '', 1) if '\\MARK\n' in t else t.replace('\\MARK', '', 1)
        else:
            t = t.replace('\\MARK', line, 1)
    return t.replace('\\MARK\n', '').replace('\\MARK', '')


def apply_lit(root, group, texts):
    """Apply the literal rules of a group to texts ({path: text}, filled on demand)."""
    log = []
    for path, a, b in LIT.get(group, []):
        full = os.path.join(root, 'src', 'game', path)
        if path not in texts:
            if not os.path.exists(full):
                log.append('MISSING FILE %s' % path)
                continue
            texts[path] = open(full, newline='', encoding='latin1').read()
        s = texts[path]
        if a in b and b in s:
            continue                    # the new text contains the old one and is already there
        if a in s:
            texts[path] = s.replace(a, b)
        elif b not in s:
            log.append('NO MATCH %s: %s' % (path, a[:70]))
    return texts, log


def overlay_files(root):
    base = os.path.join(root, 'src', 'game')
    for dp, _dn, fn in os.walk(base):
        for f in fn:
            if f.endswith('.c') or f.endswith('.h'):
                yield os.path.join(dp, f)


def plan(root, groups):
    """Compute {relpath: new text} for the chosen groups and a message log."""
    base = os.path.join(root, 'src', 'game')
    new = {}
    log = []
    for g in groups:
        _t, lg = apply_lit(root, g, new)
        log += lg
    # call rewrites on every file
    for full in overlay_files(root):
        rel = os.path.relpath(full, base).replace(os.sep, '/')
        s = new.get(rel)
        if s is None:
            s = open(full, newline='', encoding='latin1').read()
        s0 = s
        if 'USERARG' in groups:
            s = re.sub(r'\(void \*\)\s*GFL_NET_GetUserArg\(\)', 'GFL_NET_GetUserArg()', s)
            s = re.sub(r'GFL_NET_Exit\(\s*\(void \(\*\)\((?:u32|unsigned int|unsigned)\)\)\s*(\w+)\)', r'GFL_NET_Exit(\g<1>)', s)
            here = os.path.dirname(rel)
            for cf, func, ty in CALLBACKS:
                if os.path.dirname(cf) == here and (rel == cf or rel.endswith('.h')):
                    s = convert_callback(s, func, ty)
        if 'MSL' in groups and rel.endswith('.c'):
            s = libc_locals(s)
            s = strip_libc_casts(s)
            s = libc_externs(s)
        if 'SIZET' in groups:
            s = SIZET_TYPEDEF.sub('', s)
        if s != s0:
            new[rel] = s
        if not CALLRE.search(s) or not ({'CMD', 'USERARG'} & set(groups)):
            continue
        tables = set()
        t = rewrite_calls(s, tables)
        if 'CMD' in groups and tables:
            t = retype_tables(t, tables)
        if t != s:
            new[rel] = t
    if 'MSL' in groups:
        _t, lg = apply_lit(root, 'MSL2', new)
        log += lg
    # keep only files whose text really changed
    out = {}
    for rel, t in new.items():
        old = open(os.path.join(base, rel), newline='', encoding='latin1').read()
        if old != t:
            out[rel] = t
    return out, log


PC_DROP = [('dwc_main.c', 'memcmp'), ('dwc_main.c', 'strchr'), ('dwc_main.c', 'strlen'), ('dwc_main.c', 'strncpy'),
           ('gpibuddy.c', 'strstr'), ('gpiinfo.c', 'strlen'), ('gpiinfo.c', 'strncmp'), ('gsplatformutil.c', 'strlen'),
           ('gsxml.c', 'strchr'), ('gsxml.c', 'strncmp'), ('gsxml.c', 'strncpy'), ('sb_server.c', 'strcmp_nocase')]


def drop_protocheck_exceptions(root):
    """The ov009 libc rows of tools/protocheck.py EXCEPTIONS are covered by the new MSL prototypes."""
    p = os.path.join(root, 'tools', 'protocheck.py')
    if not os.path.exists(p):
        return
    t = open(p, newline='').read()
    drop = {'    ("src/game/ov009/%s", "%s"),' % (f, n) for f, n in PC_DROP}
    lines = t.split('\n')
    out = []
    skip_comment = 0
    for ln in lines:
        if ln in drop:
            continue
        if ln.startswith('    # ov009 (libdwc/GameSpy objects)'):
            skip_comment = 4            # the reason comment of the dropped rows (four lines)
        if skip_comment:
            skip_comment -= 1
            continue
        out.append(ln)
    u = '\n'.join(out)
    if u != t:
        open(p, 'w', newline='').write(u)
        print('changed tools/protocheck.py')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--root', default=REPO)
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--group', action='append', choices=['CMD', 'USERARG', 'MSL', 'SIZET'])
    ap.add_argument('--claims')
    ap.add_argument('--lane', default='P3NET')
    ap.add_argument('--force-partial', action='store_true')
    a = ap.parse_args()
    groups = a.group or ['SIZET', 'CMD', 'USERARG', 'MSL']
    root = a.root
    changes, log = plan(root, groups)
    for l in log:
        print(l)
    blocked = []
    if a.claims:
        for rel in sorted(changes):
            path = 'src/game/' + rel
            r = subprocess.run([sys.executable, a.claims, 'who', path], capture_output=True, text=True).stdout.strip()
            if r not in ('nobody', "['%s']" % a.lane):
                blocked.append((rel, r))
    print('%d files change; %d blocked' % (len(changes), len(blocked)))
    for rel, who in blocked:
        print('  blocked %s %s' % (rel, who))
    if not a.apply:
        for rel in sorted(changes):
            print('  would change', rel)
        return 0
    if blocked and not a.force_partial:
        print('not applied: claim the blocked files first (or --force-partial)')
        return 1
    skip = {rel for rel, _ in blocked}
    for rel in sorted(changes):
        if rel in skip:
            continue
        path = 'src/game/' + rel
        if a.claims:
            r = subprocess.run([sys.executable, a.claims, 'claim', a.lane, path], capture_output=True, text=True).stdout
            if 'REFUSED' in r:
                print('REFUSED', rel)
                continue
        with open(os.path.join(root, 'src', 'game', rel), 'w', newline='', encoding='latin1') as f:
            f.write(changes[rel])
        print('changed', rel)
    if 'MSL' in groups and not blocked:
        drop_protocheck_exceptions(root)
    return 0


if __name__ == '__main__':
    sys.exit(main())
