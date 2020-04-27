/*
 * FileUtil.h
 *
 *  Created on: 2017年2月21日
 *  Author: Sven
 */

#ifndef FILEUTIL_H_
#define FILEUTIL_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#ifdef _MSC_VER
#include <windows.h>
#else
#include <unistd.h>
#include <pthread.h>
#endif

namespace fileUtil {

/**
 * 文件工具类。
 *
 */
class FileUtil
{
public:
	static const string SURFFIX_PCM;

	static const string SURFFIX_TXT;

	static const string SURFFIX_CFG;

	static const string SURFFIX_LOG;

	static bool exist(const string &path);

	static bool isDirectory(const string &path);

	/**
	 * 当目录路径不存在时创建目录。
	 *
	 * @param path 路径，以"/"结尾
	 */
	static bool makeDirIfNoExist(const string &path);

	static bool delFile(const string &filePath);

	static string readFileAsString(const string &filePath);

	static string getCurrentTime();

	class DataFileHelper
	{
	private:
		pthread_mutex_t mMutex;

		const string mFileDir;

		fstream mIn;

		fstream mOut;

	public:
		DataFileHelper(const string& fileDir);

		~DataFileHelper();

		bool openReadFile(const string& filePath, bool inCurrentDir = true);

		int read(char* buffer, int bufferLen);

		string readLine();

		void rewindReadFile();

		void closeReadFile();

		void createWriteFile(const string& suffix, bool append);

		void createWriteFile(const string& filename, const string& suffix, bool append, bool inCurrentDir = true);

		bool write(const char* data, int dataLen, int offset, int writeLen);

		void closeWriteFile();

		void closeFile();
	};

};

} //namespace fileUtil

#endif /* FILEUTIL_H_ */
