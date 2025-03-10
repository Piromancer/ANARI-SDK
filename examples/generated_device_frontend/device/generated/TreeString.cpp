// Copyright 2021 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

// This file was generated by generate_device_frontend.py
// Don't make changes to this directly

#include "TreeString.h"
#include <cstdint>
namespace anari_sdk{
namespace tree{
int parameter_string_hash(const char *str) {
   static const uint32_t table[] = {0x75740017u,0x70610027u,0x706c003cu,0x0u,0x7271004eu,0x7369005du,0x0u,0x0u,0x0u,0x0u,0x0u,0x6a65006fu,0x6a69007cu,0x70650088u,0x6362009cu,0x737200b2u,0x0u,0x6a6500bdu,0x6a6500cbu,0x706f00deu,0x0u,0x0u,0x706f00e7u,0x75740018u,0x73720019u,0x6a69001au,0x6362001bu,0x7675001cu,0x7574001du,0x6665001eu,0x3430001fu,0x1000023u,0x1000024u,0x1000025u,0x1000026u,0x80000000u,0x80000001u,0x80000002u,0x80000003u,0x64630036u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x75740039u,0x6c6b0037u,0x1000038u,0x80000004u,0x6968003au,0x100003bu,0x80000005u,0x62610040u,0x0u,0x0u,0x6d6c004au,0x6e6d0041u,0x71700042u,0x55540043u,0x706f0044u,0x46450045u,0x65640046u,0x68670047u,0x66650048u,0x1000049u,0x80000006u,0x706f004bu,0x7372004cu,0x100004du,0x80000007u,0x7675004fu,0x6a690050u,0x73720051u,0x66650052u,0x64630053u,0x75740054u,0x62610055u,0x6f6e0056u,0x68670057u,0x76750058u,0x6d6c0059u,0x6261005au,0x7372005bu,0x100005cu,0x80000008u,0x73720067u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x706f006bu,0x74730068u,0x75740069u,0x100006au,0x80000009u,0x6f6e006cu,0x7574006du,0x100006eu,0x8000000au,0x67660074u,0x0u,0x0u,0x0u,0x6f6e0077u,0x75740075u,0x1000076u,0x8000000bu,0x66650078u,0x62610079u,0x7372007au,0x100007bu,0x8000000cu,0x7372007du,0x7372007eu,0x706f007fu,0x73720080u,0x53520081u,0x66650082u,0x71700083u,0x66650084u,0x62610085u,0x75740086u,0x1000087u,0x8000000du,0x62610093u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x6f6e0099u,0x73720094u,0x66650095u,0x74730096u,0x75740097u,0x1000098u,0x8000000eu,0x6665009au,0x100009bu,0x8000000fu,0x6b6a009du,0x6665009eu,0x6463009fu,0x757400a0u,0x514e00a1u,0x706f00a4u,0x0u,0x706f00aau,0x737200a5u,0x6e6d00a6u,0x626100a7u,0x6d6c00a8u,0x10000a9u,0x80000010u,0x747300abu,0x6a6900acu,0x757400adu,0x6a6900aeu,0x706f00afu,0x6f6e00b0u,0x10000b1u,0x80000011u,0x6a6900b3u,0x6e6d00b4u,0x6a6900b5u,0x757400b6u,0x6a6900b7u,0x777600b8u,0x666500b9u,0x4a4900bau,0x656400bbu,0x10000bcu,0x80000012u,0x717000c2u,0x0u,0x0u,0x0u,0x686700c7u,0x666500c3u,0x626100c4u,0x757400c5u,0x10000c6u,0x80000013u,0x696800c8u,0x757400c9u,0x10000cau,0x80000014u,0x646300d0u,0x0u,0x0u,0x0u,0x656400d5u,0x706f00d1u,0x6f6e00d2u,0x656400d3u,0x10000d4u,0x80000015u,0x666500d6u,0x434200d7u,0x7a7900d8u,0x545300d9u,0x6a6900dau,0x656400dbu,0x666500dcu,0x10000ddu,0x80000016u,0x717000dfu,0x434200e0u,0x706f00e1u,0x757400e2u,0x757400e3u,0x706f00e4u,0x6e6d00e5u,0x10000e6u,0x80000017u,0x737200e8u,0x6d6c00e9u,0x656400eau,0x514e00ebu,0x706f00eeu,0x0u,0x706f00f4u,0x737200efu,0x6e6d00f0u,0x626100f1u,0x6d6c00f2u,0x10000f3u,0x80000018u,0x747300f5u,0x6a6900f6u,0x757400f7u,0x6a6900f8u,0x706f00f9u,0x6f6e00fau,0x10000fbu,0x80000019u};
   uint32_t cur = 0x78610000u;
   for(int i = 0;cur!=0;++i) {
      uint32_t idx = cur&0xFFFFu;
      uint32_t low = (cur>>16u)&0xFFu;
      uint32_t high = (cur>>24u)&0xFFu;
      uint32_t c = (uint32_t)str[i];
      if(c>=low && c<high) {
         cur = table[idx+c-low];
      } else {
         break;
      }
      if(cur&0x80000000u) {
         return cur&0xFFFFu;
      }
      if(str[i]==0) {
         break;
      }
   }
   return -1;
}
const char *param_strings[] = {
   "attribute0",
   "attribute1",
   "attribute2",
   "attribute3",
   "back",
   "both",
   "clampToEdge",
   "color",
   "equirectangular",
   "first",
   "front",
   "left",
   "linear",
   "mirrorRepeat",
   "nearest",
   "none",
   "objectNormal",
   "objectPosition",
   "primitiveId",
   "repeat",
   "right",
   "second",
   "sideBySide",
   "topBottom",
   "worldNormal",
   "worldPosition"
};
} //namespace anari_sdk
} //namespace tree
