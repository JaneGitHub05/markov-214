% A visualizer for unfettered markov process given a certain word for a
% preestablished matrix

% input: 
%   probability matrix "wordMat" (given one word)
%   vector "wordVec" IDing specific word
%   numIter = number of steps to take
%   totalWords = number of unique words in the matrix



function lyrics = Bumblebee(wordMat, beginVec, numIter, totalWords)
    i = 0;
    numwords = size(totalWords);
    %plot words in a circle
    circ = 2*pi;
    theta = linspace(1, 2*pi, numwords(1));
    x = numwords(1)*0.2*cos(theta);
    y = numwords(1)*0.2*sin(theta);
    wordList = strings(numIter);
    figure();
    plot(x, y,'.','MarkerSize',30,'Color', 'k');
    xlim([-0.27*numwords(1) 0.27*numwords(1)]);
    ylim([-0.27*numwords(1) 0.27*numwords(1)]);
    axis equal;
    hold on;
    %label points on visual
    text(x+0.3*cos(theta)-0.015, y+0.3*sin(theta)-0.015, totalWords, 'FontSize',12); % make this better visually!
    %initialize input/output vars
    currIndex = find(beginVec==1);
    currProb = beginVec;
    colIndex = 0;
    %initialize cell array to catch data from each markov step
    data = cell(2);
    %create timer
    
    two = seconds(2);
    while i < numIter
        %find next word and also recalc matrix and vector for next word
        prevIndex = currIndex;
        data = nextWord(wordMat, currProb); % have this take vec and return vec
        currIndex = data{2};
        currProb = data{1};
        %wait two seconds
        pause(1);
        quiver(x(prevIndex), y(prevIndex), x(currIndex)-x(prevIndex), y(currIndex)-y(prevIndex),0,'LineWidth',2);
        hold on;
        colIndex = colIndex + 0.05;
        [maxProb, index] = max(currProb);
        i = i+1;
        wordList(i) = totalWords(index);
    end
    lyrics = wordList;

end

        


