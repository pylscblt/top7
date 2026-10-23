-- phpMyAdmin SQL Dump
-- version 5.2.3
-- https://www.phpmyadmin.net/
--
-- Host: db
-- Generation Time: Oct 23, 2026 at 02:36 PM
-- Server version: 8.0.46
-- PHP Version: 8.3.36

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `topseven`
--

-- --------------------------------------------------------

--
-- Table structure for table `calendar`
--

CREATE TABLE `calendar` (
  `season` tinyint NOT NULL,
  `day` tinyint NOT NULL,
  `date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `forum`
--

CREATE TABLE `forum` (
  `idx1` int NOT NULL,
  `idx2` int NOT NULL,
  `team` smallint NOT NULL,
  `player` mediumint NOT NULL,
  `season` tinyint NOT NULL DEFAULT '0',
  `day` tinyint NOT NULL,
  `date` datetime NOT NULL,
  `comment` text CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `match`
--

CREATE TABLE `match` (
  `id` int NOT NULL,
  `season` tinyint DEFAULT '0',
  `day` tinyint NOT NULL,
  `team1` tinyint NOT NULL COMMENT 'Equipe locale',
  `team2` tinyint NOT NULL COMMENT 'Equipe visiteur',
  `date` date NOT NULL,
  `time` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `password`
--

CREATE TABLE `password` (
  `Id` int NOT NULL,
  `player` mediumint NOT NULL,
  `status` tinyint NOT NULL,
  `keyword` varchar(32) NOT NULL,
  `time` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `player`
--

CREATE TABLE `player` (
  `player_idx` mediumint NOT NULL,
  `season` tinyint NOT NULL DEFAULT '0',
  `status` tinyint NOT NULL DEFAULT '0',
  `name` varchar(50) NOT NULL,
  `pseudo` varchar(40) NOT NULL,
  `captain` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Capitaine',
  `rank` tinyint NOT NULL,
  `rankFinal` tinyint NOT NULL,
  `point` smallint NOT NULL,
  `J` tinyint NOT NULL COMMENT 'Joué',
  `G` tinyint NOT NULL COMMENT 'Gagné',
  `N` tinyint NOT NULL COMMENT 'Nul',
  `P` tinyint NOT NULL COMMENT 'Perdu',
  `team` smallint NOT NULL,
  `email` varchar(120) NOT NULL,
  `password` varchar(32) NOT NULL,
  `date_reg` datetime NOT NULL,
  `pm` int NOT NULL COMMENT 'Points Marqués',
  `pe` int NOT NULL COMMENT 'Points Encaissés',
  `ve` tinyint NOT NULL COMMENT 'Victoires Extérieures',
  `evo` tinyint NOT NULL COMMENT 'Evolution',
  `fun` int NOT NULL COMMENT 'Points fun',
  `bd` tinyint NOT NULL,
  `bo` tinyint NOT NULL,
  `pc` tinyint NOT NULL COMMENT 'Points coiffeur',
  `eq` tinyint NOT NULL COMMENT 'Equipes différentes',
  `d14` tinyint DEFAULT NULL COMMENT 'Journée pour 14 équipes différentes'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- --------------------------------------------------------

--
-- Table structure for table `prono`
--

CREATE TABLE `prono` (
  `id` int NOT NULL,
  `season` tinyint NOT NULL DEFAULT '0',
  `day` tinyint NOT NULL,
  `player` smallint NOT NULL,
  `match` mediumint NOT NULL DEFAULT '0',
  `team` tinyint NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `score`
--

CREATE TABLE `score` (
  `id` int NOT NULL,
  `season` tinyint NOT NULL DEFAULT '0',
  `day` tinyint NOT NULL COMMENT 'Journée championnat',
  `team` tinyint NOT NULL COMMENT 'Equipe championnat',
  `rank` tinyint NOT NULL,
  `pm` smallint NOT NULL COMMENT 'Points marqués',
  `pe` smallint NOT NULL COMMENT 'Points encaissés',
  `pc` tinyint NOT NULL COMMENT 'Points championnat',
  `bd` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Bonus défensif',
  `bo` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Bonus offensif',
  `em` tinyint NOT NULL DEFAULT '0' COMMENT 'Essais Marqués',
  `ee` tinyint NOT NULL DEFAULT '0' COMMENT 'Essais Encaissés',
  `ve` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Victoire extérieure',
  `J` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Joué',
  `V` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Victoire',
  `N` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Nul',
  `D` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Défaite',
  `pen` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'Points pénalité'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `season`
--

CREATE TABLE `season` (
  `Id` tinyint NOT NULL,
  `title` varchar(40) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `start` date NOT NULL,
  `start_register` date NOT NULL,
  `stop_register` date NOT NULL,
  `close_forum` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `team`
--

CREATE TABLE `team` (
  `team_short` text NOT NULL,
  `team_long` varchar(50) NOT NULL,
  `team_idx` tinyint NOT NULL,
  `season` tinyint NOT NULL,
  `previous_season` tinyint NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- --------------------------------------------------------

--
-- Table structure for table `team_player`
--

CREATE TABLE `team_player` (
  `team_idx` smallint NOT NULL,
  `name` varchar(50) NOT NULL,
  `season` tinyint NOT NULL DEFAULT '0',
  `status` tinyint NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `calendar`
--
ALTER TABLE `calendar`
  ADD UNIQUE KEY `id` (`season`,`date`);

--
-- Indexes for table `forum`
--
ALTER TABLE `forum`
  ADD PRIMARY KEY (`idx1`);

--
-- Indexes for table `match`
--
ALTER TABLE `match`
  ADD PRIMARY KEY (`id`),
  ADD KEY `team1` (`team1`),
  ADD KEY `team2` (`team2`),
  ADD KEY `season_day` (`season`,`day`);

--
-- Indexes for table `password`
--
ALTER TABLE `password`
  ADD PRIMARY KEY (`Id`);

--
-- Indexes for table `player`
--
ALTER TABLE `player`
  ADD PRIMARY KEY (`player_idx`);

--
-- Indexes for table `prono`
--
ALTER TABLE `prono`
  ADD PRIMARY KEY (`id`),
  ADD KEY `day` (`day`),
  ADD KEY `player` (`player`);

--
-- Indexes for table `score`
--
ALTER TABLE `score`
  ADD PRIMARY KEY (`id`),
  ADD KEY `team_i` (`team`),
  ADD KEY `day_i` (`day`);

--
-- Indexes for table `season`
--
ALTER TABLE `season`
  ADD UNIQUE KEY `Id` (`Id`);

--
-- Indexes for table `team`
--
ALTER TABLE `team`
  ADD UNIQUE KEY `Idx` (`team_idx`,`season`);

--
-- Indexes for table `team_player`
--
ALTER TABLE `team_player`
  ADD UNIQUE KEY `team_idx` (`team_idx`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `forum`
--
ALTER TABLE `forum`
  MODIFY `idx1` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `match`
--
ALTER TABLE `match`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `password`
--
ALTER TABLE `password`
  MODIFY `Id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `player`
--
ALTER TABLE `player`
  MODIFY `player_idx` mediumint NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `prono`
--
ALTER TABLE `prono`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `score`
--
ALTER TABLE `score`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `team_player`
--
ALTER TABLE `team_player`
  MODIFY `team_idx` smallint NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
