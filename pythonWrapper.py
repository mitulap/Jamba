from ctypes import cdll
# importing jamba lib using ctypes
lib = cdll.LoadLibrary('./jamba.so')
# Getting jamba compiled 
prompt = "> "

class JambaJuiceMain(object):
    def __init__(self):
        self.obj = lib.Jamba_new()

    def JambaJuice_req(self, worker, req):
        lib.Jamba_processRequestMainMethod(self.obj, worker , req)

print "Hi Welcome to Jamba Juice...!"
print "Please enter number of Juice Requests"
requests = input(prompt)
print "Please enter number of blenders or workers"
workers = input(prompt)

jabmaJuiceShop = JambaJuiceMain()
jabmaJuiceShop.JambaJuice_req(workers, requests);