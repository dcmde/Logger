#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <map>

class Logger {

protected:

    void open(const std::string &path, const std::string &name) {
        setPath(path);
        std::string temp = path + name + " " + datetime() + ".txt";
        map_ofstream[name] = new std::ofstream(temp.c_str(), std::ios::out);
    }

    void open(const std::string &name) {
        open(path_, name);
    }

    void setPath(const std::string &path) {
        path_ = path;
    }

    std::ofstream &write() {
        return *map_ofstream.begin()->second;
    }

    std::ofstream &write(const std::string &name) {
        if (map_ofstream.find(name) == map_ofstream.end()) {
            open(path_, name);
        }
        return *map_ofstream[name];
    }

    void close() {
        for (auto item : map_ofstream) {
            item.second->close();
        }
        map_ofstream.clear();
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

    static std::string timestamp() {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, 80, "%H-%M-%S", timeinfo);
        return std::string(buffer);
    }

    std::map<std::string, std::ofstream *> map_ofstream;
    std::string path_;
};

#endif // LOGGER_HPP
