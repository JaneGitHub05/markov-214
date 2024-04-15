%read in function i.e. driver

%need to take inputs for 
% file name, 
% num words ahead, numiter
% and start word begin


table1 = readtable('transform.csv',"NumHeaderLines", 2, "VariableNamingRule", "preserve");

table1.Properties.VariableNames

beginWord = "know"
numWords = width(table1);
i=0;
startVec = (words==beginWord);

matrix = table1{:,:}



output = Bumblebee(matrix, startVec, 6, numWords, false);






% ask for inputs?// come back to this, only takes list of words and matrix





