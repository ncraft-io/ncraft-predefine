from conans import ConanFile, CMake

class NcraftPredefineConan(ConanFile):
   settings = "os", "compiler", "build_type", "arch"
   generators = "cmake"

   def imports(self):
      self.copy("*.dll", dst="bin", src="bin") # From bin to bin
      self.copy("*.dylib*", dst="bin", src="lib") # From lib to bin

   def build(self):
      cmake = CMake(self)
      cmake.configure()
      cmake.build()
