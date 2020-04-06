#include <string>
#include <iostream>
#include <chrono>
using namespace std::chrono;

class Stopwatch {
public:
  Stopwatch(std::string s = "watch") : m_start(system_clock::time_point::min()), m_prefix(s) {Start();}
  ~Stopwatch() { Show(); }
private:
  inline void Start() { m_start = system_clock::now();}
  inline void Clear() { m_start = system_clock::time_point::min(); }
  inline bool IsStarted() const { return (m_start.time_since_epoch() != system_clock::duration(0));}
  unsigned long GetMs() {
      if(IsStarted()) {
          system_clock::duration diff;
          diff = system_clock::now() - m_start;
          return (unsigned)(duration_cast<milliseconds>(diff).count());
      }
      return 0;
  }
  inline void Show() {std::cout << m_prefix << ": " << GetMs() << "ms" << std::endl;}

private:
  std::string m_prefix;
  std::chrono::system_clock::time_point m_start;
};

