class horners: 
    def __init__(self, c, x):
        self.__coefficients = c 
        self.__x = x
        self.__result = self.hornersCalculate

    def hornersCalculate(self):
        length = len(self.__coefficients)
        calc = self.__coefficients[length]
        for i in range(length-1, 1):
            calc = calc*self.__x
            calc = calc + self.__coefficients[i]
        return calc



