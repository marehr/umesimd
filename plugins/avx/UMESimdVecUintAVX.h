// The MIT License (MIT)
//
// Copyright (c) 2015 CERN
//
// Author: Przemyslaw Karpinski
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//
//  This piece of code was developed as part of ICE-DIP project at CERN.
//  "ICE-DIP is a European Industrial Doctorate project funded by the European Community's 
//  7th Framework programme Marie Curie Actions under grant PITN-GA-2012-316596".
//

#ifndef UME_SIMD_VEC_UINT_AVX_H_
#define UME_SIMD_VEC_UINT_AVX_H_

#include <type_traits>
#include "../../UMESimdInterface.h"
#include "../UMESimdPluginScalarEmulation.h"
#include <immintrin.h>

#include "UMESimdMaskAVX.h"
#include "UMESimdSwizzleAVX.h"

namespace UME {
namespace SIMD {

    // ********************************************************************************************
    // UNSIGNED INTEGER VECTORS
    // ********************************************************************************************
    template<typename VEC_TYPE, uint32_t VEC_LEN>
    struct SIMDVecAVX_u_traits {
        // Generic trait class not containing type definition so that only correct explicit
        // type definitions are compiled correctly
    };

    // 8b vectors
    template<>
    struct SIMDVecAVX_u_traits<uint8_t, 1> {
        typedef int8_t       SCALAR_INT_TYPE;
        typedef SIMDMask1    MASK_TYPE;
        typedef SIMDSwizzle1 SWIZZLE_MASK_TYPE;
    };

    // 16b vectors
    template<>
    struct SIMDVecAVX_u_traits<uint8_t, 2> {
        typedef SIMDVecAVX_u<uint8_t, 1> HALF_LEN_VEC_TYPE;
        typedef int8_t                   SCALAR_INT_TYPE;
        typedef SIMDMask2                MASK_TYPE;
        typedef SIMDSwizzle2             SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint16_t, 1> {
        typedef int16_t      SCALAR_INT_TYPE;
        typedef SIMDMask1    MASK_TYPE;
        typedef SIMDSwizzle1 SWIZZLE_MASK_TYPE;
    };

    // 32b vectors
    template<>
    struct SIMDVecAVX_u_traits<uint8_t, 4> {
        typedef SIMDVecAVX_u<uint8_t, 2> HALF_LEN_VEC_TYPE;
        typedef int8_t                   SCALAR_INT_TYPE;
        typedef SIMDMask4                MASK_TYPE;
        typedef SIMDSwizzle4             SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint16_t, 2> {
        typedef SIMDVecAVX_u<uint16_t, 2> HALF_LEN_VEC_TYPE;
        typedef int16_t                   SCALAR_INT_TYPE;
        typedef SIMDMask2                 MASK_TYPE;
        typedef SIMDSwizzle2              SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint32_t, 1> {
        typedef int32_t      SCALAR_INT_TYPE;
        typedef SIMDMask1    MASK_TYPE;
        typedef SIMDSwizzle1 SWIZZLE_MASK_TYPE;
    };

    // 64b vectors
    template<>
    struct SIMDVecAVX_u_traits<uint8_t, 8> {
        typedef SIMDVecAVX_u<uint8_t, 4> HALF_LEN_VEC_TYPE;
        typedef int8_t                   SCALAR_INT_TYPE;
        typedef SIMDMask8                MASK_TYPE;
        typedef SIMDSwizzle8             SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint16_t, 4> {
        typedef SIMDVecAVX_u<uint16_t, 2> HALF_LEN_VEC_TYPE;
        typedef int16_t                   SCALAR_INT_TYPE;
        typedef SIMDMask4                 MASK_TYPE;
        typedef SIMDSwizzle4              SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint32_t, 2> {
        typedef SIMDVecAVX_u<uint32_t, 1> HALF_LEN_VEC_TYPE;
        typedef int32_t                   SCALAR_INT_TYPE;
        typedef SIMDMask2                 MASK_TYPE;
        typedef SIMDSwizzle2              SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint64_t, 1> {
        typedef int64_t      SCALAR_INT_TYPE;
        typedef SIMDMask1    MASK_TYPE;
        typedef SIMDSwizzle1 SWIZZLE_MASK_TYPE;
    };

    // 128b vectors
    template<>
    struct SIMDVecAVX_u_traits<uint8_t, 16> {
        typedef SIMDVecAVX_u<uint8_t, 8>  HALF_LEN_VEC_TYPE;
        typedef int8_t                    SCALAR_INT_TYPE;
        typedef SIMDMask16                MASK_TYPE;
        typedef SIMDSwizzle16             SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint16_t, 8> {
        typedef SIMDVecAVX_u<uint16_t, 4> HALF_LEN_VEC_TYPE;
        typedef int16_t                   SCALAR_INT_TYPE;
        typedef SIMDMask8                 MASK_TYPE;
        typedef SIMDSwizzle8              SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint32_t, 4> {
        typedef SIMDVecAVX_u<uint32_t, 2> HALF_LEN_VEC_TYPE;
        typedef int32_t                   SCALAR_INT_TYPE;
        typedef SIMDMask4                 MASK_TYPE;
        typedef SIMDSwizzle4              SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint64_t, 2> {
        typedef SIMDVecAVX_u<uint64_t, 1> HALF_LEN_VEC_TYPE;
        typedef int64_t                   SCALAR_INT_TYPE;
        typedef SIMDMask2                 MASK_TYPE;
        typedef SIMDSwizzle2              SWIZZLE_MASK_TYPE;
    };

    // 256b vectors
    template<>
    struct SIMDVecAVX_u_traits<uint8_t, 32> {
        typedef SIMDVecAVX_u<uint8_t, 16> HALF_LEN_VEC_TYPE;
        typedef int8_t                    SCALAR_INT_TYPE;
        typedef SIMDMask32                MASK_TYPE;
        typedef SIMDSwizzle32             SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint16_t, 16> {
        typedef SIMDVecAVX_u<uint16_t, 8> HALF_LEN_VEC_TYPE;
        typedef int16_t                   SCALAR_INT_TYPE;
        typedef SIMDMask16                MASK_TYPE;
        typedef SIMDSwizzle16             SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint32_t, 8> {
        typedef SIMDVecAVX_u<uint32_t, 4> HALF_LEN_VEC_TYPE;
        typedef int32_t                   SCALAR_INT_TYPE;
        typedef SIMDMask8                 MASK_TYPE;
        typedef SIMDSwizzle8              SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint64_t, 4> {
        typedef SIMDVecAVX_u<uint64_t, 2> HALF_LEN_VEC_TYPE;
        typedef int64_t                   SCALAR_INT_TYPE;
        typedef SIMDMask4                 MASK_TYPE;
        typedef SIMDSwizzle4             SWIZZLE_MASK_TYPE;
    };

    // 512b vectors
    template<>
    struct SIMDVecAVX_u_traits<uint8_t, 64> {
        typedef SIMDVecAVX_u<uint8_t, 32> HALF_LEN_VEC_TYPE;
        typedef int8_t                    SCALAR_INT_TYPE;
        typedef SIMDMask64                MASK_TYPE;
        typedef SIMDSwizzle64             SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint16_t, 32> {
        typedef SIMDVecAVX_u<uint16_t, 16> HALF_LEN_VEC_TYPE;
        typedef int16_t                    SCALAR_INT_TYPE;
        typedef SIMDMask32                 MASK_TYPE;
        typedef SIMDSwizzle32              SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint32_t, 16> {
        typedef SIMDVecAVX_u<uint32_t, 8> HALF_LEN_VEC_TYPE;
        typedef int32_t                   SCALAR_INT_TYPE;
        typedef SIMDMask16                MASK_TYPE;
        typedef SIMDSwizzle16             SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint64_t, 8> {
        typedef SIMDVecAVX_u<uint64_t, 4> HALF_LEN_VEC_TYPE;
        typedef int64_t                   SCALAR_INT_TYPE;
        typedef SIMDMask8                 MASK_TYPE;
        typedef SIMDSwizzle8              SWIZZLE_MASK_TYPE;
    };

    // 1024b vectors
    template<>
    struct SIMDVecAVX_u_traits<uint8_t, 128> {
        typedef SIMDVecAVX_u<uint8_t, 128> HALF_LEN_VEC_TYPE;
        typedef int8_t                     SCALAR_INT_TYPE;
        typedef SIMDMask128                MASK_TYPE;
        typedef SIMDSwizzle128             SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint16_t, 64> {
        typedef SIMDVecAVX_u<uint16_t, 32> HALF_LEN_VEC_TYPE;
        typedef int16_t                    SCALAR_INT_TYPE;
        typedef SIMDMask64                 MASK_TYPE;
        typedef SIMDSwizzle64              SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint32_t, 32> {
        typedef SIMDVecAVX_u<uint32_t, 16> HALF_LEN_VEC_TYPE;
        typedef int32_t                    SCALAR_INT_TYPE;
        typedef SIMDMask32                 MASK_TYPE;
        typedef SIMDSwizzle32              SWIZZLE_MASK_TYPE;
    };

    template<>
    struct SIMDVecAVX_u_traits<uint64_t, 16> {
        typedef SIMDVecAVX_u<uint64_t, 8> HALF_LEN_VEC_TYPE;
        typedef int64_t                   SCALAR_INT_TYPE;
        typedef SIMDMask16                MASK_TYPE;
        typedef SIMDSwizzle16             SWIZZLE_MASK_TYPE;
    };

    // ***************************************************************************
    // *
    // *    Implementation of unsigned integer SIMDx_8u, SIMDx_16u, SIMDx_32u, 
    // *    and SIMDx_64u.
    // *
    // *    This implementation uses scalar emulation available through to 
    // *    SIMDVecUnsignedInterface.
    // *
    // ***************************************************************************
    template<typename SCALAR_UINT_TYPE, uint32_t VEC_LEN>
    class SIMDVecAVX_u final :
        public SIMDVecUnsignedInterface<
        SIMDVecAVX_u<SCALAR_UINT_TYPE, VEC_LEN>, // DERIVED_UINT_VEC_TYPE
        SCALAR_UINT_TYPE,                        // SCALAR_UINT_TYPE
        VEC_LEN,
        typename SIMDVecAVX_u_traits<SCALAR_UINT_TYPE, VEC_LEN>::MASK_TYPE,
        typename SIMDVecAVX_u_traits<SCALAR_UINT_TYPE, VEC_LEN>::SWIZZLE_MASK_TYPE>,
        public SIMDVecPackableInterface<
        SIMDVecAVX_u<SCALAR_UINT_TYPE, VEC_LEN>,        // DERIVED_VEC_TYPE
        typename SIMDVecAVX_u_traits<SCALAR_UINT_TYPE, VEC_LEN>::HALF_LEN_VEC_TYPE> // DERIVED_HALF_VEC_TYPE
    {
    public:
        typedef SIMDVecEmuRegister<SCALAR_UINT_TYPE, VEC_LEN>                                   VEC_EMU_REG;

        typedef typename SIMDVecAVX_u_traits<SCALAR_UINT_TYPE, VEC_LEN>::SCALAR_INT_TYPE  SCALAR_INT_TYPE;
        typedef typename SIMDVecAVX_u_traits<SCALAR_UINT_TYPE, VEC_LEN>::MASK_TYPE        MASK_TYPE;

        // Conversion operators require access to private members.
        friend class SIMDVecAVX_i<SCALAR_INT_TYPE, VEC_LEN>;

    private:
        // This is the only data member and it is a low level representation of vector register.
        VEC_EMU_REG mVec;

    public:
        // ZERO-CONSTR
        inline SIMDVecAVX_u() : mVec() {};

        // SET-CONSTR
        inline explicit SIMDVecAVX_u(SCALAR_UINT_TYPE i) : mVec(i) {};

        // LOAD-CONSTR - Construct by loading from memory
        inline explicit SIMDVecAVX_u(SCALAR_UINT_TYPE const *p) { this->load(p); };

        inline SIMDVecAVX_u(SCALAR_UINT_TYPE i0, SCALAR_UINT_TYPE i1) {
            mVec.insert(0, i0);  mVec.insert(1, i1);
        }

        inline SIMDVecAVX_u(SCALAR_UINT_TYPE i0, SCALAR_UINT_TYPE i1, SCALAR_UINT_TYPE i2, SCALAR_UINT_TYPE i3) {
            mVec.insert(0, i0);  mVec.insert(1, i1);  mVec.insert(2, i2);  mVec.insert(3, i3);
        }

        inline SIMDVecAVX_u(SCALAR_UINT_TYPE i0, SCALAR_UINT_TYPE i1, SCALAR_UINT_TYPE i2, SCALAR_UINT_TYPE i3, SCALAR_UINT_TYPE i4, SCALAR_UINT_TYPE i5, SCALAR_UINT_TYPE i6, SCALAR_UINT_TYPE i7)
        {
            mVec.insert(0, i0);  mVec.insert(1, i1);  mVec.insert(2, i2);  mVec.insert(3, i3);
            mVec.insert(4, i4);  mVec.insert(5, i5);  mVec.insert(6, i6);  mVec.insert(7, i7);
        }

        inline SIMDVecAVX_u(SCALAR_UINT_TYPE i0, SCALAR_UINT_TYPE i1, SCALAR_UINT_TYPE i2, SCALAR_UINT_TYPE i3, SCALAR_UINT_TYPE i4, SCALAR_UINT_TYPE i5, SCALAR_UINT_TYPE i6, SCALAR_UINT_TYPE i7,
            SCALAR_UINT_TYPE i8, SCALAR_UINT_TYPE i9, SCALAR_UINT_TYPE i10, SCALAR_UINT_TYPE i11, SCALAR_UINT_TYPE i12, SCALAR_UINT_TYPE i13, SCALAR_UINT_TYPE i14, SCALAR_UINT_TYPE i15)
        {
            mVec.insert(0, i0);    mVec.insert(1, i1);    mVec.insert(2, i2);    mVec.insert(3, i3);
            mVec.insert(4, i4);    mVec.insert(5, i5);    mVec.insert(6, i6);    mVec.insert(7, i7);
            mVec.insert(8, i8);    mVec.insert(9, i9);    mVec.insert(10, i10);  mVec.insert(11, i11);
            mVec.insert(12, i12);  mVec.insert(13, i13);  mVec.insert(14, i14);  mVec.insert(15, i15);
        }

        inline SIMDVecAVX_u(SCALAR_UINT_TYPE i0, SCALAR_UINT_TYPE i1, SCALAR_UINT_TYPE i2, SCALAR_UINT_TYPE i3, SCALAR_UINT_TYPE i4, SCALAR_UINT_TYPE i5, SCALAR_UINT_TYPE i6, SCALAR_UINT_TYPE i7,
            SCALAR_UINT_TYPE i8, SCALAR_UINT_TYPE i9, SCALAR_UINT_TYPE i10, SCALAR_UINT_TYPE i11, SCALAR_UINT_TYPE i12, SCALAR_UINT_TYPE i13, SCALAR_UINT_TYPE i14, SCALAR_UINT_TYPE i15,
            SCALAR_UINT_TYPE i16, SCALAR_UINT_TYPE i17, SCALAR_UINT_TYPE i18, SCALAR_UINT_TYPE i19, SCALAR_UINT_TYPE i20, SCALAR_UINT_TYPE i21, SCALAR_UINT_TYPE i22, SCALAR_UINT_TYPE i23,
            SCALAR_UINT_TYPE i24, SCALAR_UINT_TYPE i25, SCALAR_UINT_TYPE i26, SCALAR_UINT_TYPE i27, SCALAR_UINT_TYPE i28, SCALAR_UINT_TYPE i29, SCALAR_UINT_TYPE i30, SCALAR_UINT_TYPE i31)
        {
            mVec.insert(0, i0);    mVec.insert(1, i1);    mVec.insert(2, i2);    mVec.insert(3, i3);
            mVec.insert(4, i4);    mVec.insert(5, i5);    mVec.insert(6, i6);    mVec.insert(7, i7);
            mVec.insert(8, i8);    mVec.insert(9, i9);    mVec.insert(10, i10);  mVec.insert(11, i11);
            mVec.insert(12, i12);  mVec.insert(13, i13);  mVec.insert(14, i14);  mVec.insert(15, i15);
            mVec.insert(16, i16);  mVec.insert(17, i17);  mVec.insert(18, i18);  mVec.insert(19, i19);
            mVec.insert(20, i20);  mVec.insert(21, i21);  mVec.insert(22, i22);  mVec.insert(23, i23);
            mVec.insert(24, i24);  mVec.insert(25, i25);  mVec.insert(26, i26);  mVec.insert(27, i27);
            mVec.insert(28, i28);  mVec.insert(29, i29);  mVec.insert(30, i30);  mVec.insert(31, i31);
        }

        // Override Access operators
        inline SCALAR_UINT_TYPE operator[] (uint32_t index) const {
            return mVec[index];
        }

        // Override Mask Access operators
        inline IntermediateMask<SIMDVecAVX_u, MASK_TYPE> operator[] (MASK_TYPE const & mask) {
            return IntermediateMask<SIMDVecAVX_u, MASK_TYPE>(mask, static_cast<SIMDVecAVX_u &>(*this));
        }

        // insert[] (scalar)
        inline SIMDVecAVX_u & insert(uint32_t index, SCALAR_UINT_TYPE value) {
            mVec.insert(index, value);
            return *this;
        }

        inline  operator SIMDVecAVX_i<SCALAR_INT_TYPE, VEC_LEN>() const {
            SIMDVecAVX_i<SCALAR_INT_TYPE, VEC_LEN> retval;
            for (uint32_t i = 0; i < VEC_LEN; i++) {
                retval.insert(i, (SCALAR_INT_TYPE)mVec[i]);
            }
            return retval;
        }
    };

    // ***************************************************************************
    // *
    // *    Partial specialization of unsigned integer SIMD for VEC_LEN == 1.
    // *    This specialization is necessary to eliminate PACK operations from
    // *    being used on SIMD1 types.
    // *
    // ***************************************************************************
    template<typename SCALAR_UINT_TYPE>
    class SIMDVecAVX_u<SCALAR_UINT_TYPE, 1> :
        public SIMDVecUnsignedInterface<
        SIMDVecAVX_u<SCALAR_UINT_TYPE, 1>, // DERIVED_UINT_VEC_TYPE
        SCALAR_UINT_TYPE,                  // SCALAR_UINT_TYPE
        1,
        typename SIMDVecAVX_u_traits<SCALAR_UINT_TYPE, 1>::MASK_TYPE,
        typename SIMDVecAVX_u_traits<SCALAR_UINT_TYPE, 1>::SWIZZLE_MASK_TYPE>
    {
    public:
        typedef SIMDVecEmuRegister<SCALAR_UINT_TYPE, 1>                                   VEC_EMU_REG;

        typedef typename SIMDVecAVX_u_traits<SCALAR_UINT_TYPE, 1>::SCALAR_INT_TYPE  SCALAR_INT_TYPE;
        typedef typename SIMDVecAVX_u_traits<SCALAR_UINT_TYPE, 1>::MASK_TYPE        MASK_TYPE;

        // Conversion operators require access to private members.
        friend class SIMDVecAVX_i<SCALAR_INT_TYPE, 1>;

    private:
        // This is the only data member and it is a low level representation of vector register.
        VEC_EMU_REG mVec;

    public:
        // ZERO-CONSTR
        inline SIMDVecAVX_u() : mVec() {};

        // SET-CONSTR
        inline explicit SIMDVecAVX_u(SCALAR_UINT_TYPE i) : mVec(i) {};

        // LOAD-CONSTR - Construct by loading from memory
        inline explicit SIMDVecAVX_u(SCALAR_UINT_TYPE const *p) { this->load(p); };

        // Override Access operators
        inline SCALAR_UINT_TYPE operator[] (uint32_t index) const {
            return mVec[index];
        }

        // Override Mask Access operators
        inline IntermediateMask<SIMDVecAVX_u, MASK_TYPE> operator[] (MASK_TYPE const & mask) {
            return IntermediateMask<SIMDVecAVX_u, MASK_TYPE>(mask, static_cast<SIMDVecAVX_u &>(*this));
        }

        // insert[] (scalar)
        inline SIMDVecAVX_u & insert(uint32_t index, SCALAR_UINT_TYPE value) {
            mVec.insert(index, value);
            return *this;
        }

        inline  operator SIMDVecAVX_i<SCALAR_INT_TYPE, 1>() const {
            SIMDVecAVX_i<SCALAR_INT_TYPE, 1> retval(mVec[0]);
            return retval;
        }
    };

    // ********************************************************************************************
    // UNSIGNED INTEGER VECTORS specialization
    // ********************************************************************************************
    template<>
    class SIMDVecAVX_u<uint32_t, 8> :
        public SIMDVecUnsignedInterface<
        SIMDVecAVX_u<uint32_t, 8>,
        uint32_t,
        8,
        SIMDMask8,
        SIMDSwizzle8>,
        public SIMDVecPackableInterface<
        SIMDVecAVX_u<uint32_t, 8>,
        SIMDVecAVX_u<uint32_t, 4 >>
    {
    public:
        // Conversion operators require access to private members.
        friend class SIMDVecAVX_i<int32_t, 8>;
        friend class SIMDVecAVX_f<float, 8>;

    private:
        __m256i mVec;

        inline SIMDVecAVX_u(__m256i & x) { this->mVec = x; }
    public:

        // ZERO-CONSTR
        inline SIMDVecAVX_u() {
            mVec = _mm256_setzero_si256();
        }

        // SET-CONSTR
        inline explicit SIMDVecAVX_u(uint32_t i) {
            mVec = _mm256_set1_epi32(i);
        }

        // LOAD-CONSTR
        inline explicit SIMDVecAVX_u(uint32_t const * p) {
            mVec = _mm256_loadu_si256((__m256i*)p);
        }

        inline SIMDVecAVX_u(uint32_t i0, uint32_t i1, uint32_t i2, uint32_t i3,
            uint32_t i4, uint32_t i5, uint32_t i6, uint32_t i7)
        {
            mVec = _mm256_setr_epi32(i0, i1, i2, i3, i4, i5, i6, i7);
        }

        inline uint32_t extract(uint32_t index) const {
            //UME_PERFORMANCE_UNOPTIMAL_WARNING(); // This routine can be optimized
            alignas(32) uint32_t raw[8];
            _mm256_store_si256((__m256i*)raw, mVec);
            return raw[index];
        }

        // Override Access operators
        inline uint32_t operator[] (uint32_t index) const {
            return extract(index);
        }

        // Override Mask Access operators
        inline IntermediateMask<SIMDVecAVX_u, SIMDMask8> operator[] (SIMDMask8 const & mask) {
            return IntermediateMask<SIMDVecAVX_u, SIMDMask8>(mask, static_cast<SIMDVecAVX_u &>(*this));
        }

        // insert[] (scalar)
        inline SIMDVecAVX_u & insert(uint32_t index, uint32_t value) {
            //UME_PERFORMANCE_UNOPTIMAL_WARNING();
            alignas(32) uint32_t raw[8];
            _mm256_store_si256((__m256i*)raw, mVec);
            raw[index] = value;
            mVec = _mm256_load_si256((__m256i*)raw);
            return *this;
        }
        // STOREA
        inline uint32_t * storea(uint32_t * addrAligned) {
            _mm256_store_si256((__m256i*)addrAligned, mVec);
            return addrAligned;
        }

        // ADDV
        inline SIMDVecAVX_u add(SIMDVecAVX_u const & b) const {
            __m128i t0 = _mm256_extractf128_si256(b.mVec, 0);
            __m128i t1 = _mm256_extractf128_si256(mVec, 0);
            __m128i t2 = _mm_add_epi32(t0, t1);
            __m128i t3 = _mm256_extractf128_si256(b.mVec, 1);
            __m128i t4 = _mm256_extractf128_si256(mVec, 1);
            __m128i t5 = _mm_add_epi32(t3, t4);
            __m256i t6 = _mm256_insertf128_si256(_mm256_castsi128_si256(t2), (t5), 0x1);
            return SIMDVecAVX_u(t6);
        }

        inline SIMDVecAVX_u operator+ (SIMDVecAVX_u const & b) const {
            return add(b);
        }

        // MADDV
        inline SIMDVecAVX_u add(SIMDMask8 const & mask, SIMDVecAVX_u const & b) const {
            __m128i t0 = _mm256_extractf128_si256(b.mVec, 0);
            __m128i t1 = _mm256_extractf128_si256(mVec, 0);
            __m128i t2 = _mm_add_epi32(t0, t1);
            __m128i t3 = _mm_blendv_epi8(t1, t2, _mm256_extractf128_si256(mask.mMask, 0));
            __m128i t4 = _mm256_extractf128_si256(b.mVec, 1);
            __m128i t5 = _mm256_extractf128_si256(mVec, 1);
            __m128i t6 = _mm_add_epi32(t4, t5);
            __m128i t7 = _mm_blendv_epi8(t5, t6, _mm256_extractf128_si256(mask.mMask, 1));
            __m256i t8 = _mm256_insertf128_si256(_mm256_castsi128_si256(t3), (t7), 0x1);
            return SIMDVecAVX_u(t8);
        }

        // ADDS
        inline SIMDVecAVX_u add(uint32_t b) const {
            __m128i t0 = _mm_set1_epi32(b);
            __m128i t1 = _mm256_extractf128_si256(mVec, 0);
            __m128i t2 = _mm_add_epi32(t0, t1);
            __m128i t3 = _mm256_extractf128_si256(mVec, 1);
            __m128i t4 = _mm_add_epi32(t0, t3);
            __m256i t5 = _mm256_insertf128_si256(_mm256_castsi128_si256(t2), (t4), 0x1);
            return SIMDVecAVX_u(t5);
        }

        // MADDS
        inline SIMDVecAVX_u add(SIMDMask8 const & mask, uint32_t b) const {
            __m128i t0 = _mm_set1_epi32(b);
            __m128i t1 = _mm256_extractf128_si256(mVec, 0);
            __m128i t2 = _mm_add_epi32(t0, t1);
            __m128i t3 = _mm_blendv_epi8(t1, t2, _mm256_extractf128_si256(mask.mMask, 0));
            __m128i t4 = _mm256_extractf128_si256(mVec, 1);
            __m128i t5 = _mm_add_epi32(t0, t4);
            __m128i t6 = _mm_blendv_epi8(t4, t5, _mm256_extractf128_si256(mask.mMask, 1));
            __m256i t7 = _mm256_insertf128_si256(_mm256_castsi128_si256(t3), (t6), 0x1);
            return SIMDVecAVX_u(t7);
        }

        // ADDVA
        inline SIMDVecAVX_u & adda(SIMDVecAVX_u const & b) {
            __m128i t0 = _mm256_extractf128_si256(b.mVec, 0);
            __m128i t1 = _mm256_extractf128_si256(mVec, 0);
            __m128i t2 = _mm_add_epi32(t0, t1);
            __m128i t3 = _mm256_extractf128_si256(b.mVec, 1);
            __m128i t4 = _mm256_extractf128_si256(mVec, 1);
            __m128i t5 = _mm_add_epi32(t3, t4);
            mVec = _mm256_insertf128_si256(_mm256_castsi128_si256(t2), (t5), 0x1);
            return *this;
        }

        // MADDVA
        inline SIMDVecAVX_u & adda(SIMDMask8 const & mask, SIMDVecAVX_u const & b) {
            __m128i t0 = _mm256_extractf128_si256(b.mVec, 0);
            __m128i t1 = _mm256_extractf128_si256(mVec, 0);
            __m128i t2 = _mm_add_epi32(t0, t1);
            __m128i t3 = _mm_blendv_epi8(t1, t2, _mm256_extractf128_si256(mask.mMask, 0));
            __m128i t4 = _mm256_extractf128_si256(b.mVec, 1);
            __m128i t5 = _mm256_extractf128_si256(mVec, 1);
            __m128i t6 = _mm_add_epi32(t4, t5);
            __m128i t7 = _mm_blendv_epi8(t5, t6, _mm256_extractf128_si256(mask.mMask, 1));
            mVec = _mm256_insertf128_si256(_mm256_castsi128_si256(t3), (t7), 0x1);
            return *this;
        }

        // ADDSA 
        inline SIMDVecAVX_u & adda(uint32_t b) {
            __m128i t0 = _mm_set1_epi32(b);
            __m128i t1 = _mm256_extractf128_si256(mVec, 0);
            __m128i t2 = _mm_add_epi32(t0, t1);
            __m128i t3 = _mm256_extractf128_si256(mVec, 1);
            __m128i t4 = _mm_add_epi32(t0, t3);
            mVec = _mm256_insertf128_si256(_mm256_castsi128_si256(t2), (t4), 0x1);
            return *this;
        }

        // MADDSA
        inline SIMDVecAVX_u & adda(SIMDMask8 const & mask, uint32_t b) {
            __m128i t0 = _mm_set1_epi32(b);
            __m128i t1 = _mm256_extractf128_si256(mVec, 0);
            __m128i t2 = _mm_add_epi32(t0, t1);
            __m128i t3 = _mm_blendv_epi8(t1, t2, _mm256_extractf128_si256(mask.mMask, 0));
            __m128i t4 = _mm256_extractf128_si256(mVec, 1);
            __m128i t5 = _mm_add_epi32(t0, t4);
            __m128i t6 = _mm_blendv_epi8(t4, t5, _mm256_extractf128_si256(mask.mMask, 1));
            mVec = _mm256_insertf128_si256(_mm256_castsi128_si256(t3), (t6), 0x1);
            return *this;
        }

        // MULV
        inline SIMDVecAVX_u mul(SIMDVecAVX_u const & b) {
            __m128i a_low = _mm256_extractf128_si256(mVec, 0);
            __m128i a_high = _mm256_extractf128_si256(mVec, 1);
            __m128i b_low = _mm256_extractf128_si256(b.mVec, 0);
            __m128i b_high = _mm256_extractf128_si256(b.mVec, 1);
            __m128i r_low = _mm_mullo_epi32(a_low, b_low);
            __m128i r_high = _mm_mullo_epi32(a_high, b_high);
            __m256i ret = _mm256_setzero_si256();
            ret = _mm256_insertf128_si256(ret, r_low, 0);
            ret = _mm256_insertf128_si256(ret, r_high, 1);
            return SIMDVecAVX_u(ret);
        }
        // MMULV
        inline SIMDVecAVX_u mul(SIMDMask8 const & mask, SIMDVecAVX_u const & b) {
            __m128i a_low = _mm256_extractf128_si256(mVec, 0);
            __m128i a_high = _mm256_extractf128_si256(mVec, 1);
            __m128i b_low = _mm256_extractf128_si256(b.mVec, 0);
            __m128i b_high = _mm256_extractf128_si256(b.mVec, 1);
            __m128i r_low = _mm_mullo_epi32(a_low, b_low);
            __m128i r_high = _mm_mullo_epi32(a_high, b_high);
            __m128i m_low = _mm256_extractf128_si256(mask.mMask, 0);
            __m128i m_high = _mm256_extractf128_si256(mask.mMask, 1);
            r_low = _mm_blendv_epi8(a_low, r_low, m_low);
            r_high = _mm_blendv_epi8(a_high, r_high, m_high);
            __m256i ret = _mm256_setzero_si256();
            ret = _mm256_insertf128_si256(ret, r_low, 0);
            ret = _mm256_insertf128_si256(ret, r_high, 1);
            return SIMDVecAVX_u(ret);
        }
        // MULS
        inline SIMDVecAVX_u mul(uint32_t b) {
            __m128i a_low = _mm256_extractf128_si256(mVec, 0);
            __m128i a_high = _mm256_extractf128_si256(mVec, 1);
            __m128i b_vec = _mm_set1_epi32(b);
            __m128i r_low = _mm_mullo_epi32(a_low, b_vec);
            __m128i r_high = _mm_mullo_epi32(a_high, b_vec);
            __m256i ret = _mm256_setzero_si256();
            ret = _mm256_insertf128_si256(ret, r_low, 0);
            ret = _mm256_insertf128_si256(ret, r_high, 1);
            return SIMDVecAVX_u(ret);
        }
        // MMULS
        inline SIMDVecAVX_u mul(SIMDMask8 const & mask, uint32_t b) {
            __m128i a_low = _mm256_extractf128_si256(mVec, 0);
            __m128i a_high = _mm256_extractf128_si256(mVec, 1);
            __m128i b_vec = _mm_set1_epi32(b);
            __m128i r_low = _mm_mullo_epi32(a_low, b_vec);
            __m128i r_high = _mm_mullo_epi32(a_high, b_vec);
            __m128i m_low = _mm256_extractf128_si256(mask.mMask, 0);
            __m128i m_high = _mm256_extractf128_si256(mask.mMask, 1);
            r_low = _mm_blendv_epi8(a_low, r_low, m_low);
            r_high = _mm_blendv_epi8(a_high, r_high, m_high);
            __m256i ret = _mm256_setzero_si256();
            ret = _mm256_insertf128_si256(ret, r_low, 0);
            ret = _mm256_insertf128_si256(ret, r_high, 1);
            return SIMDVecAVX_u(ret);
        }
        // CMPEQV
        inline SIMDMask8 cmpeq(SIMDVecAVX_u const & b) {
            __m128i a_low = _mm256_extractf128_si256(mVec, 0);
            __m128i a_high = _mm256_extractf128_si256(mVec, 1);
            __m128i b_low = _mm256_extractf128_si256(b.mVec, 0);
            __m128i b_high = _mm256_extractf128_si256(b.mVec, 1);

            __m128i r_low = _mm_cmpeq_epi32(a_low, b_low);
            __m128i r_high = _mm_cmpeq_epi32(a_high, b_high);

            __m256i ret = _mm256_setzero_si256();
            ret = _mm256_insertf128_si256(ret, r_low, 0);
            ret = _mm256_insertf128_si256(ret, r_high, 1);
            return SIMDMask8(ret);
        }
        // CMPEQS
        inline SIMDMask8 cmpeq(uint32_t b) {
            __m128i b_vec = _mm_set1_epi32(b);
            __m128i a_low = _mm256_extractf128_si256(mVec, 0);
            __m128i a_high = _mm256_extractf128_si256(mVec, 1);

            __m128i r_low = _mm_cmpeq_epi32(a_low, b_vec);
            __m128i r_high = _mm_cmpeq_epi32(a_high, b_vec);

            __m256i ret = _mm256_setzero_si256();
            ret = _mm256_insertf128_si256(ret, r_low, 0);
            ret = _mm256_insertf128_si256(ret, r_high, 1);
            return SIMDMask8(ret);
        }

        // GATHERS
        SIMDVecAVX_u & gather(uint32_t* baseAddr, uint64_t* indices) {
            UME_PERFORMANCE_UNOPTIMAL_WARNING();
            alignas(32) uint32_t raw[8] = { baseAddr[indices[0]], baseAddr[indices[1]], baseAddr[indices[2]], baseAddr[indices[3]],
                baseAddr[indices[4]], baseAddr[indices[5]], baseAddr[indices[6]], baseAddr[indices[7]] };
            mVec = _mm256_load_si256((__m256i*)raw);
            return *this;
        }
        // MGATHERS
        SIMDVecAVX_u & gather(SIMDMask8 const & mask, uint32_t* baseAddr, uint64_t* indices) {
            UME_PERFORMANCE_UNOPTIMAL_WARNING();
            alignas(32) uint32_t raw[8] = { baseAddr[indices[0]], baseAddr[indices[1]], baseAddr[indices[2]], baseAddr[indices[3]],
                baseAddr[indices[4]], baseAddr[indices[5]], baseAddr[indices[6]], baseAddr[indices[7]] };
            __m128i a_low = _mm256_extractf128_si256(mVec, 0);
            __m128i a_high = _mm256_extractf128_si256(mVec, 1);
            __m128i b_low = _mm_load_si128((__m128i*)&raw[0]);
            __m128i b_high = _mm_load_si128((__m128i*)&raw[4]);
            __m128i m_low = _mm256_extractf128_si256(mask.mMask, 0);
            __m128i m_high = _mm256_extractf128_si256(mask.mMask, 1);
            __m128i r_low = _mm_blendv_epi8(a_low, b_low, m_low);
            __m128i r_high = _mm_blendv_epi8(a_high, b_high, m_high);
            mVec = _mm256_insertf128_si256(mVec, r_low, 0);
            mVec = _mm256_insertf128_si256(mVec, r_high, 1);
            return *this;
        }
        // GATHERV
        SIMDVecAVX_u & gather(uint32_t* baseAddr, SIMDVecAVX_u const & indices) {
            UME_PERFORMANCE_UNOPTIMAL_WARNING();
            alignas(32) uint32_t rawInd[8];
            alignas(32) uint32_t raw[8];

            _mm256_store_si256((__m256i*) rawInd, indices.mVec);
            for (int i = 0; i < 8; i++) { raw[i] = baseAddr[rawInd[i]]; }
            mVec = _mm256_load_si256((__m256i*)raw);
            return *this;
        }
        // MGATHERV
        SIMDVecAVX_u & gather(SIMDMask8 const & mask, uint32_t* baseAddr, SIMDVecAVX_u const & indices) {
            UME_PERFORMANCE_UNOPTIMAL_WARNING();
            alignas(32) uint32_t rawInd[8];
            alignas(32) uint32_t raw[8];

            _mm256_store_si256((__m256i*) rawInd, indices.mVec);
            for (int i = 0; i < 8; i++) { raw[i] = baseAddr[rawInd[i]]; }
            __m128i a_low = _mm256_extractf128_si256(mVec, 0);
            __m128i a_high = _mm256_extractf128_si256(mVec, 1);
            __m128i b_low = _mm_load_si128((__m128i*)&raw[0]);
            __m128i b_high = _mm_load_si128((__m128i*)&raw[4]);
            __m128i m_low = _mm256_extractf128_si256(mask.mMask, 0);
            __m128i m_high = _mm256_extractf128_si256(mask.mMask, 1);
            __m128i r_low = _mm_blendv_epi8(a_low, b_low, m_low);
            __m128i r_high = _mm_blendv_epi8(a_high, b_high, m_high);
            mVec = _mm256_insertf128_si256(mVec, r_low, 0);
            mVec = _mm256_insertf128_si256(mVec, r_high, 1);
            return *this;
        }
        // SCATTERS
        uint32_t* scatter(uint32_t* baseAddr, uint64_t* indices) {
            UME_PERFORMANCE_UNOPTIMAL_WARNING();
            alignas(32) uint32_t raw[8];
            _mm256_store_si256((__m256i*) raw, mVec);
            for (int i = 0; i < 8; i++) { baseAddr[indices[i]] = raw[i]; };
            return baseAddr;
        }
        // MSCATTERS
        uint32_t* scatter(SIMDMask8 const & mask, uint32_t* baseAddr, uint64_t* indices) {
            UME_PERFORMANCE_UNOPTIMAL_WARNING();
            alignas(32) uint32_t raw[8];
            alignas(32) uint32_t rawMask[8];
            _mm256_store_si256((__m256i*) raw, mVec);
            _mm256_store_si256((__m256i*) rawMask, mask.mMask);
            for (int i = 0; i < 8; i++) { if (rawMask[i] == SIMDMask8::TRUE()) baseAddr[indices[i]] = raw[i]; };
            return baseAddr;
        }
        // SCATTERV
        uint32_t* scatter(uint32_t* baseAddr, SIMDVecAVX_u const & indices) {
            UME_PERFORMANCE_UNOPTIMAL_WARNING();
            alignas(32) uint32_t raw[8];
            alignas(32) uint32_t rawIndices[8];
            _mm256_store_si256((__m256i*) raw, mVec);
            _mm256_store_si256((__m256i*) rawIndices, indices.mVec);
            for (int i = 0; i < 8; i++) { baseAddr[rawIndices[i]] = raw[i]; };
            return baseAddr;
        }
        // MSCATTERV
        uint32_t* scatter(SIMDMask8 const & mask, uint32_t* baseAddr, SIMDVecAVX_u const & indices) {
            UME_PERFORMANCE_UNOPTIMAL_WARNING();
            alignas(32) uint32_t raw[8];
            alignas(32) uint32_t rawIndices[8];
            alignas(32) uint32_t rawMask[8];
            _mm256_store_si256((__m256i*) raw, mVec);
            _mm256_store_si256((__m256i*) rawIndices, indices.mVec);
            _mm256_store_si256((__m256i*) rawMask, mask.mMask);
            for (int i = 0; i < 8; i++) {
                if (rawMask[i] == SIMDMask8::TRUE())
                    baseAddr[rawIndices[i]] = raw[i];
            };
            return baseAddr;
        }

        inline  operator SIMDVecAVX_i<int32_t, 8> const ();
    };

    template<>
    class SIMDVecAVX_u<uint32_t, 16> :
        public SIMDVecUnsignedInterface<
        SIMDVecAVX_u<uint32_t, 16>,
        uint32_t,
        16,
        SIMDMask16,
        SIMDSwizzle16>,
        public SIMDVecPackableInterface<
        SIMDVecAVX_u<uint32_t, 16>,
        SIMDVecAVX_u<uint32_t, 8 >>
    {
    public:
        // Conversion operators require access to private members.
        friend class SIMDVecAVX_i<int32_t, 16>;
        friend class SIMDVecAVX_f<float, 16>;

    private:
        __m256i mVecLo;
        __m256i mVecHi;

        inline SIMDVecAVX_u(__m256i & x_lo, __m256i & x_hi) {
            this->mVecLo = x_lo;
            this->mVecHi = x_hi;
        }
    public:

        // ZERO-CONSTR
        inline SIMDVecAVX_u() {
            mVecLo = _mm256_setzero_si256();
            mVecHi = mVecLo;
        }

        // SET-CONSTR
        inline explicit SIMDVecAVX_u(uint32_t i) {
            mVecLo = _mm256_set1_epi32(i);
            mVecHi = mVecLo;
        }

        // LOAD-CONSTR
        inline explicit SIMDVecAVX_u(uint32_t const * p) {
            mVecLo = _mm256_loadu_si256((__m256i*)p);
            mVecHi = _mm256_loadu_si256((__m256i*)(p + 8));
        }

        inline SIMDVecAVX_u(uint32_t i0, uint32_t i1, uint32_t i2, uint32_t i3,
            uint32_t i4, uint32_t i5, uint32_t i6, uint32_t i7,
            uint32_t i8, uint32_t i9, uint32_t i10, uint32_t i11,
            uint32_t i12, uint32_t i13, uint32_t i14, uint32_t i15)
        {
            mVecLo = _mm256_setr_epi32(i0, i1, i2, i3, i4, i5, i6, i7);
            mVecHi = _mm256_setr_epi32(i8, i9, i10, i11, i12, i13, i14, i15);
        }

        inline uint32_t extract(uint32_t index) const {
            //UME_PERFORMANCE_UNOPTIMAL_WARNING(); // This routine can be optimized
            alignas(32) uint32_t raw[8];
            uint32_t value;
            if (index < 8) {
                _mm256_store_si256((__m256i*)raw, mVecLo);
                value = raw[index];
            }
            else {
                _mm256_store_si256((__m256i*)raw, mVecHi);
                value = raw[index - 8];
            }
            return value;
        }

        // Override Access operators
        inline uint32_t operator[] (uint32_t index) const {
            return extract(index);
        }

        // Override Mask Access operators
        inline IntermediateMask<SIMDVecAVX_u, SIMDMask16> operator[] (SIMDMask16 const & mask) {
            return IntermediateMask<SIMDVecAVX_u, SIMDMask16>(mask, static_cast<SIMDVecAVX_u &>(*this));
        }

        // insert[] (scalar)
        inline SIMDVecAVX_u & insert(uint32_t index, uint32_t value) {
            //UME_PERFORMANCE_UNOPTIMAL_WARNING();
            alignas(32) uint32_t raw[8];
            if (index < 8) {
                _mm256_store_si256((__m256i*)raw, mVecLo);
                raw[index] = value;
                mVecLo = _mm256_load_si256((__m256i*)raw);
            }
            else {
                _mm256_store_si256((__m256i*)raw, mVecHi);
                raw[index - 8] = value;
                mVecHi = _mm256_load_si256((__m256i*)raw);
            }
            return *this;
        }
        // STOREA
        // ADDV
        // MADDV
        // ADDS
        // MADDS
        // ADDVA
        // MADDVA
        // ADDSA 
        // MADDSA
        // MULV
        // MMULV
        // MULS
        // MMULS
        // CMPEQV
        // CMPEQS
        // UNIQUE
        // GATHERS
        // MGATHERS
        // GATHERV
        // MGATHERV
        // SCATTERS
        // MSCATTERS
        // SCATTERV
        // MSCATTERV

        inline  operator SIMDVecAVX_i<int32_t, 16> const ();
    };

}
}

#endif