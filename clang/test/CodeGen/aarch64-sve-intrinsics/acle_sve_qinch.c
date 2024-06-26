// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -S -disable-O0-optnone -Werror -Wall -o /dev/null %s
#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

// CHECK-LABEL: @test_svqinch_n_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqinch.n32(i32 [[OP:%.*]], i32 31, i32 1)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svqinch_n_s32i(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqinch.n32(i32 [[OP:%.*]], i32 31, i32 1)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
int32_t test_svqinch_n_s32(int32_t op)
{
  return SVE_ACLE_FUNC(svqinch,_n_s32,,)(op, 1);
}

// CHECK-LABEL: @test_svqinch_n_s32_1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqinch.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svqinch_n_s32_1i(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqinch.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
int32_t test_svqinch_n_s32_1(int32_t op)
{
  return SVE_ACLE_FUNC(svqinch,_n_s32,,)(op, 16);
}

// CHECK-LABEL: @test_svqinch_n_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.sqinch.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svqinch_n_s64l(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.sqinch.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
int64_t test_svqinch_n_s64(int64_t op)
{
  return SVE_ACLE_FUNC(svqinch,_n_s64,,)(op, 1);
}

// CHECK-LABEL: @test_svqinch_n_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.uqinch.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svqinch_n_u32j(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.uqinch.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
uint32_t test_svqinch_n_u32(uint32_t op)
{
  return SVE_ACLE_FUNC(svqinch,_n_u32,,)(op, 16);
}

// CHECK-LABEL: @test_svqinch_n_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.uqinch.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svqinch_n_u64m(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.uqinch.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svqinch_n_u64(uint64_t op)
{
  return SVE_ACLE_FUNC(svqinch,_n_u64,,)(op, 1);
}

// CHECK-LABEL: @test_svqinch_pat_n_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqinch.n32(i32 [[OP:%.*]], i32 30, i32 16)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z22test_svqinch_pat_n_s32i(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqinch.n32(i32 [[OP:%.*]], i32 30, i32 16)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
int32_t test_svqinch_pat_n_s32(int32_t op)
{
  return SVE_ACLE_FUNC(svqinch_pat,_n_s32,,)(op, SV_MUL3, 16);
}

// CHECK-LABEL: @test_svqinch_pat_n_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.sqinch.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z22test_svqinch_pat_n_s64l(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.sqinch.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
int64_t test_svqinch_pat_n_s64(int64_t op)
{
  return SVE_ACLE_FUNC(svqinch_pat,_n_s64,,)(op, SV_ALL, 1);
}

// CHECK-LABEL: @test_svqinch_pat_n_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.uqinch.n32(i32 [[OP:%.*]], i32 0, i32 16)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z22test_svqinch_pat_n_u32j(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.uqinch.n32(i32 [[OP:%.*]], i32 0, i32 16)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
uint32_t test_svqinch_pat_n_u32(uint32_t op)
{
  return SVE_ACLE_FUNC(svqinch_pat,_n_u32,,)(op, SV_POW2, 16);
}

// CHECK-LABEL: @test_svqinch_pat_n_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.uqinch.n64(i64 [[OP:%.*]], i32 1, i32 1)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z22test_svqinch_pat_n_u64m(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.uqinch.n64(i64 [[OP:%.*]], i32 1, i32 1)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svqinch_pat_n_u64(uint64_t op)
{
  return SVE_ACLE_FUNC(svqinch_pat,_n_u64,,)(op, SV_VL1, 1);
}

// CHECK-LABEL: @test_svqinch_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.sqinch.nxv8i16(<vscale x 8 x i16> [[OP:%.*]], i32 31, i32 16)
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svqinch_s16u11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.sqinch.nxv8i16(<vscale x 8 x i16> [[OP:%.*]], i32 31, i32 16)
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
svint16_t test_svqinch_s16(svint16_t op)
{
  return SVE_ACLE_FUNC(svqinch,_s16,,)(op, 16);
}

// CHECK-LABEL: @test_svqinch_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.uqinch.nxv8i16(<vscale x 8 x i16> [[OP:%.*]], i32 31, i32 1)
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svqinch_u16u12__SVUint16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.uqinch.nxv8i16(<vscale x 8 x i16> [[OP:%.*]], i32 31, i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
svuint16_t test_svqinch_u16(svuint16_t op)
{
  return SVE_ACLE_FUNC(svqinch,_u16,,)(op, 1);
}

// CHECK-LABEL: @test_svqinch_pat_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.sqinch.nxv8i16(<vscale x 8 x i16> [[OP:%.*]], i32 2, i32 16)
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svqinch_pat_s16u11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.sqinch.nxv8i16(<vscale x 8 x i16> [[OP:%.*]], i32 2, i32 16)
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
svint16_t test_svqinch_pat_s16(svint16_t op)
{
  return SVE_ACLE_FUNC(svqinch_pat,_s16,,)(op, SV_VL2, 16);
}

// CHECK-LABEL: @test_svqinch_pat_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.uqinch.nxv8i16(<vscale x 8 x i16> [[OP:%.*]], i32 3, i32 1)
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svqinch_pat_u16u12__SVUint16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.uqinch.nxv8i16(<vscale x 8 x i16> [[OP:%.*]], i32 3, i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
svuint16_t test_svqinch_pat_u16(svuint16_t op)
{
  return SVE_ACLE_FUNC(svqinch_pat,_u16,,)(op, SV_VL3, 1);
}
