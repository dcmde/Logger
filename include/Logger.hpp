#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>

class Logger {

protected:

    void open(const std::string &path, const std::string &name) {
        std::string temp = path + name + " " + datetime() + ".txt";
        ofs_ = new std::ofstream(temp.c_str(), std::ios::out);
    }

    std::ofstream &write() {
        return *ofs_;
    }

    void close() {
        ofs_->close();
        free(ofs_);
    }

    static std::string datetime() {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, 80, "%d-%m-%Y-%H-%M-%S", timeinfo);
        return std::string(buffer);
    }

    std::ofstream *ofs_;
};

#endif // LOGGER_HPP
