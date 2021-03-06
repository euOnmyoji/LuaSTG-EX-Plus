﻿#pragma once

#include "E2DGlobal.hpp"
#include "E2DSound.hpp"
#include "fcyIO/fcyStream.h"

namespace Eyes2D {
	namespace Sound {
		//暴力解码所有内容到内存的屑ogg解码器
		class EYESDLLAPI OggDecoder : public Decoder {
		private:
			//std::string m_Type;        //文件类型，一般为WAVE
			uint16_t m_FormatTag;      //编码方式，一般未压缩的WAV文件此项为1
			uint16_t m_Channels;       //声道数量
			uint32_t m_SamplesPerSec;  //每秒采样次数
			uint32_t m_AvgBytesPerSec; //每秒传输字节
			uint16_t m_BlockAlign;     //采样对齐，每采样一次需要多少字节
			uint16_t m_BitsPerSample;  //每个采样的大小
			uint16_t m_ExtendData;     //拓展数据
			uint8_t* m_DataBuffer;     //解码出来的数据
			uint32_t m_DataSize;       //数据大小
		private:
			struct OggFileCallbackFunc;
		public:
			OggDecoder(fcyStream* stream);
			~OggDecoder();
		public:
			uint16_t GetChannels() { return m_Channels; }
			uint32_t GetSamplesPerSec() { return m_SamplesPerSec; }
			uint32_t GetAvgBytesPerSec() { return m_AvgBytesPerSec; }
			uint16_t GetBlockAlign() { return m_BlockAlign; }
			uint16_t GetBitsPerSample() { return m_BitsPerSample; }
			uint8_t* GetDataBuffer() { return m_DataBuffer; }
			uint32_t GetDataSize() { return m_DataSize; }
		};
	}
}
